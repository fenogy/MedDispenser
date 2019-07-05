
#define C1	10
#define C2	20
#define C3	30
#define C4	40
#define C5	50
#define C6	60
#define C7	70
#define C8	80

void ClearLaserTxBuffer();
void ClearLaserRxBuffer();
void ClearLaserSubString();

int8 startIndex;
int8 endIndex;
int8 tempIndex;
char LaserSubString[16];

int8 colon1Received;
int8 enterReceived;
int8 commandLength = 0;
int8 Cmd = 255;
int8 Target = 255;
extern unsigned int8 oldTarget;

struct Command{


	short availableFlag;
	short cmdChopped;

	char Command[3];
	char *ptrValues[36];
	int32  Values[12];
	char errString[36];
	char strValues[12][8];

} currentCommand;  


void Kernal(){
		
	int i = 0;
	int j = 0;
	int k = 0;

	int noOfColons = 0;
	int noOfEnters = 0;
	int1 isCommandSuspect= 0;

	colon1Received = 0;
	enterReceived = 0;
	
	while(k<16){																	// Swipe through the FIFO

		switch(hwRxFIFO[k]){

			case	'>'	:	noOfColons++;											// Mark if a colon is received
							break;
			case	0x0D:	noOfEnters++;											// Mark is an Enter is received // CHANGED FROM 0X0D TO 0X0A ON 2009.09.23
							break;
			default		:   break;
	
		}

		k++;
	}

	if((noOfColons == 1)){
	if((noOfEnters == 1)){

			isCommandSuspect = TRUE;
	}
	}

	if((noOfColons > 1) || (noOfEnters > 1)){										// if junk received we clear the buffer here
	
			ClearLaserRxBuffer();									 				// commented on 2009.09.21 due to a problem
			noOfColons = 0;															// Edited on 2010.12.28
			noOfEnters = 0;
			return;
	}


	if(isCommandSuspect == TRUE){													// we process more if the command format is correct

	
 		while((tempIndex<16)&&(currentCommand.availableFlag==FALSE)){  // this loop will swipe through the Laser buffer for a valid command

			
			if((hwRxFIFO[tempIndex]=='>') && colon1Received==0){
			
				#ASM
				nop;
				nop;
				nop;
				nop;
				#ENDASM

				colon1Received=10;
				startIndex=tempIndex+1;
			}

			if((hwRxFIFO[tempIndex]==0x0d) && (colon1Received == 10) && (enterReceived==0)){

				enterReceived=10;
				endIndex=tempIndex;
			}


			if(colon1Received==10 && enterReceived==10){

				colon1Received=0;
				enterReceived =0;
				currentCommand.availableFlag=TRUE;			
 	  			clearLaserSubString();	

																					// NOW WE DELETE ANY PREVIOUS COMMAND
        		if((startIndex<endIndex)){         									// This is true when a command not extends back begining of the array
        
        			for(i=startIndex,j=0;i<=endIndex;i++,j++){    							// just copy it n take it seperately

						LaserSubString[j]=HwRxFIFO[(startIndex+j)];
                		
					}
					commandLength = endIndex - startIndex;
					ClearLaserRxBuffer();
				}
			}

    		tempIndex++;
		}	
		
		tempIndex=0;
	}

	if(currentCommand.availableFlag==TRUE){

		if(LaserSubString[0] == 'C' && LaserSubString[1] == '1'){
			Cmd = C1;
			Target = 1;
			printf("Target 1");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '2'){
			Cmd = C2;
			Target = 2;
			printf("Target 2");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '3'){
			Cmd = C3;
			Target = 3;
			printf("Target 3");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '4'){
			Cmd = C4;
			Target = 4;
			printf("Target 4");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '5'){
			Cmd = C5;
			Target = 5;
			printf("Target 5");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '6'){
			Cmd = C6;
			Target = 6;
			printf("Target 6");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '7'){
			Cmd = C7;
			Target = 7;
			printf("Target 7");
		}else if(LaserSubString[0] == 'C' && LaserSubString[1] == '8'){
			Cmd = C8;
			Target = 8;
			printf("Target 8");
		}else if(LaserSubString[0] == 'S' && LaserSubString[1] == 'T'){

			if(oldTarget == Target){
			printf("C%d,1\r\n",Target);
			}else{
			printf("C%d,0\r\n",Target);
			}
		}
		currentCommand.availableFlag= FALSE;																			// we dont clear the laserSubstring here ...we clear it when a new command is available
	}
}

//void SDkernal(){
//
//	int i,j;
//
//	for(i=0;i<32;i++){
//
//		if( hwRxFIFO[i] == 0x0d){
//
//			LaserCmd = 0;			
////			currentLaserCommand.Command[0] = hwRxFIFO[0];
////			currentLaserCommand.Command[1] = hwRxFIFO[1];
//			
//			for(j=0;j<=16;j++){   					
//				LaserSubString[j]=HwRxFIFO[j];
//			}
//      
//			currentLaserCommand.availableFlag=TRUE;
//
//			ClearLaserRxBuffer();
//			break;
//
//		}
//
//		if(hwRxFIFO[i] == '>'){
//
//			ClearLaserRxBuffer();
//			return ;
//		}
//
//      	}
//
//}






void QueLaserBuffer(char* str){

	int i=0;

	ClearLaserTxBuffer();

	i=strlen(str);
	HwSerialTxFIFO(str,i);
	hwTxStatus=0;

}

void ClearLaserTxBuffer(){
	
	int i=0;

	for(i=0;i<16;i++){

		hwTxFIFO[i]=0;

	}
    hwTxStatus=0;
}

void ClearLaserRxBuffer(){

	int i=0;
	hwRxStatus = 0;
	for(i=0;i<16;i++){

		hwRxFIFO[i]=0;

	}

    hwRxStatus=0;

}


void ClearLaserSubString(){

	int i;

	for(i=0;i<16;i++){

	LaserSubString[i]=0;

	}
}