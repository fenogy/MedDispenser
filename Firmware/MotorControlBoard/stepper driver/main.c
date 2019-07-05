#include "main.h"
#include <string.h>
#include "HWManager.c"
#include "Kernal.c"

#define ZERO	PIN_D0

#define ONE		PIN_D7
#define TWO		PIN_D6
#define THREE	PIN_D5
#define FOUR	PIN_D4

#define POS1	10
#define POS2	20
#define POS3	30
#define POS4	40
#define STOP	50

#define MOTOR_DIR_CW  10
#define MOTOR_DIR_CCW 20
#define MOTOR_HALT    50

#define TRUE	1
#define FALSE	0

#define SENSOR1 PIN_E2
#define SENSOR2 PIN_E1
#define SENSOR3 PIN_E0

unsigned int16 StepDly = 8;
unsigned int8 flag = 0;
unsigned int8 motorState =  POS1;
unsigned int8 motorRotation = 255;
unsigned int8 sensorVal = 0;
unsigned int16 TickCount = 0;
unsigned int8 sampleArray[8] = {0,0,0,0,0,0,0,0};
unsigned int8 fineTuning[8] = {0,0,0,0,0,0,0,0};
unsigned int8 prevState = 255;
unsigned int8 currState = 255;
unsigned int8 prevPinB0 = 255;
unsigned int8 currPinB0 = 255;
unsigned int8 i = 0;
unsigned int8 oldTarget = 255;
int1 fillSampleArray = FALSE;
int8 x = 0;

void CW();
int8 ProcessSampleArray(int8 *t);

//#int_RDA 
//void  RDA_isr(void)                      
//{   
//                              
//	//putc('k');
//	
//   clear_interrupt(INT_RDA);
//                                                     
//}    

#INT_TIMER0        
 void TimerInt()
 {   

	TickCount++;

	if(TickCount > 10000){
		TickCount = 1;
	}
	if(motorRotation == MOTOR_DIR_CW){

		switch(motorState){

			case POS1	: 	output_high(ONE);
							output_low(TWO);
							output_low(THREE);
							output_low(FOUR);
							motorState = POS2;
							break;   
			case POS2	: 	output_low(ONE);
							output_high(TWO);
							output_low(THREE);
							output_low(FOUR);
							motorState = POS3;
							break;  
			case POS3	: 	output_low(ONE);
							output_low(TWO);
							output_high(THREE);
							output_low(FOUR);
							motorState = POS4;
							break; 
			case POS4	: 	output_low(ONE);
							output_low(TWO);
							output_low(THREE);
							output_high(FOUR);
							motorState = POS1;
							break; 
			case STOP	:   output_low(ONE);
							output_low(TWO);
							output_low(THREE);
							output_low(FOUR);
							break; 
			default	 	: break;
		}
	}else{

							output_low(ONE);
							output_low(TWO);
							output_low(THREE);
							output_low(FOUR);
	}
   if(flag==0){
		flag =1;
		output_high(ZERO);
	}else{
		output_low(ZERO);
		flag = 0;
	}
   set_timer0(55555);               
   //bit_clear(INTCON,2);                                     // CLEAR TIMER 0 OVERFLOW FLAG
	clear_interrupt(int_timer0);


}  

void main()
{

   	setup_adc_ports(NO_ANALOGS|VSS_VDD);
   	setup_adc(ADC_CLOCK_DIV_2);
   	setup_psp(PSP_DISABLED);
   	setup_spi(SPI_SS_DISABLED);
   	setup_wdt(WDT_OFF);
   	setup_timer_0(RTCC_INTERNAL);
   	setup_timer_1(T1_DISABLED);
   	setup_timer_2(T2_DISABLED,0,1);
   	setup_comparator(NC_NC_NC_NC);
   	setup_vref(FALSE);

   	enable_interrupts(GLOBAL);
	enable_interrupts(INT_RDA);
   	enable_interrupts(INT_TIMER0);
   	set_timer0(55555); 

	SET_TRIS_B(0x07);

   	output_drive(ZERO);
	output_drive(ONE);
	output_drive(TWO);
	output_drive(THREE);
	output_drive(FOUR);

	output_low(ONE);
	output_low(TWO);
	output_low(THREE);
	output_low(FOUR);

//	while(1){
//	output_high(ZERO);
//	}
	currentCommand.availableFlag = FALSE;
	
	fineTuning[0] = 100;
	fineTuning[6] = 190;
	fineTuning[7] = 100;
	fineTuning[5] = 100;
	fineTuning[4] = 100;
	//CW();
HwPutc(20);
HwPutc(20);
   while(1){
   
    
	if((TickCount % 5) == 0){
x = PORTE;
		if(prevPinB0 == 255)
		   currPinB0 = (PORTE & 0x4);		//OK its just the begining we check how the PORTB.P0

		currPinB0 = (PORTE & 0x4);			//Get the PORTB.P0 state

		if(currPinB0 != prevPinB0){			//PORTB.P0 has changed its state

			prevPinB0 = currPinB0;
			prevState = ProcessSampleArray(sampleArray);
			printf("state %d \r\n",prevState);
			

			if(Target != 255 && prevState == (Target-1)){
	
				//motorState = STOP;
				delay_ms(fineTuning[Target-1]);
				motorRotation = MOTOR_HALT;
				oldTarget = Target;
//				delay_ms(2000); 
//				motorState = POS1;
//				Target = 255;
			}


			//Clear the sampleArray and start filling a new one
			for(i = 0; i < 8; i++)
				sampleArray[i] = 0;

			fillSampleArray = TRUE;
		}
		
		sensorVal = 0x7 - (PORTB & 0x7);
		sampleArray[sensorVal] ++;

	//printf("value %d \r\n",sensorVal);
	}

	if((TickCount % 10) == 0){

		if(Target == 255){

			//motorState = STOP;
			motorRotation = MOTOR_HALT;
		}
		if(oldTarget != Target){
			//motorState = POS1;
			motorRotation = MOTOR_DIR_CW;
		}
		Kernal();
		if(currentCommand.availableFlag==TRUE){
			QueLaserBuffer(LaserSubString);
			currentCommand.availableFlag=FALSE;
			ClearLaserSubString();
		}

	}
	//delay_ms(100);
//	putc('A');
//	delay_ms(10);
//   output_high(ZERO);
//   delay_ms(1000);
//   output_low(ZERO);
//   delay_ms(1000);
   
   }

}

void CW(){

while(1){

	output_high(ONE);
	output_low(TWO);
	output_low(THREE);
	output_low(FOUR);

	//output_high(ZERO);
	delay_ms(StepDly);

	output_low(ONE);
	output_high(TWO);
	output_low(THREE);
	output_low(FOUR);

	//output_low(ZERO);
	delay_ms(StepDly);

	output_low(ONE);
	output_low(TWO);
	output_high(THREE);
	output_low(FOUR);

	//output_high(ZERO);
	delay_ms(StepDly);

	output_low(ONE);
	output_low(TWO);
	output_low(THREE);
	output_high(FOUR);

	//output_low(ZERO);
	delay_ms(StepDly);



}

}

int8 ProcessSampleArray(int8 *t){
	
	int8 maximum; 
	int8 index = 0;
	int8 j=0;
	
	maximum = t[0];

	for (j=0; j<8; j++) {

    	if (t[j] > maximum) {
        	maximum = t[j];   	// maximum
        	index = j; 			// comparing index
    	}
	}
	
	for (j=0; j<8; j++) {

    	if (t[j] > maximum) {
        	maximum = t[j];   	// maximum
        	index = j; 			// comparing index
    	}
	}

	if(t[index] > 15)
		return index;
	else
		return 255;
}

//2013.1.24
//#include "main.h"
//
//#define ZERO	PIN_D0
//
//#define ONE		PIN_D7
//#define TWO		PIN_D6
//#define THREE	PIN_D5
//#define FOUR	PIN_D4
//
//#define POS1	10
//#define POS2	20
//#define POS3	30
//#define POS4	40
//#define STOP	50
//
//#define SENSOR1 PIN_B0
//#define SENSOR2 PIN_B1
//#define SENSOR3 PIN_B2
//
//unsigned int16 StepDly = 8;
//unsigned int8 flag = 0;
//unsigned int8 motorState =  POS1;
//unsigned int8 sensorVal = 0;
//void CW();
//
//#int_RDA 
//void  RDA_isr(void)                      
//{   
//                              
//	//putc('k');
//	
//   clear_interrupt(INT_RDA);
//                                                     
//}    
//
//#INT_TIMER0        
// void TimerInt()
// {   
//
//	switch(motorState){
//
//		case POS1	: 	output_high(ONE);
//						output_low(TWO);
//						output_low(THREE);
//						output_low(FOUR);
//						motorState = POS2;
//						break;   
//		case POS2	: 	output_low(ONE);
//						output_high(TWO);
//						output_low(THREE);
//						output_low(FOUR);
//						motorState = POS3;
//						break;  
//		case POS3	: 	output_low(ONE);
//						output_low(TWO);
//						output_high(THREE);
//						output_low(FOUR);
//						motorState = POS4;
//						break; 
//		case POS4	: 	output_low(ONE);
//						output_low(TWO);
//						output_low(THREE);
//						output_high(FOUR);
//						motorState = POS1;
//						break; 
//		case STOP	: break; 
//		default	 	: break;
//	}
//   if(flag==0){
//		flag =1;
//		output_high(ZERO);
//	}else{
//		output_low(ZERO);
//		flag = 0;
//	}
//   set_timer0(55000);               
//   //bit_clear(INTCON,2);                                     // CLEAR TIMER 0 OVERFLOW FLAG
//	clear_interrupt(int_timer0);
//
//
//}  
//
//void main()
//{
//
//   	setup_adc_ports(NO_ANALOGS|VSS_VDD);
//   	setup_adc(ADC_CLOCK_DIV_2);
//   	setup_psp(PSP_DISABLED);
//   	setup_spi(SPI_SS_DISABLED);
//   	setup_wdt(WDT_OFF);
//   	setup_timer_0(RTCC_INTERNAL);
//   	setup_timer_1(T1_DISABLED);
//   	setup_timer_2(T2_DISABLED,0,1);
//   	setup_comparator(NC_NC_NC_NC);
//   	setup_vref(FALSE);
//
//   	enable_interrupts(GLOBAL);
//	enable_interrupts(INT_RDA);
//   	enable_interrupts(INT_TIMER0);
//   	set_timer0(15555); 
//
//	SET_TRIS_B(0x07);
//
//   	output_drive(ZERO);
//	output_drive(ONE);
//	output_drive(TWO);
//	output_drive(THREE);
//	output_drive(FOUR);
//
//	output_low(ONE);
//	output_low(TWO);
//	output_low(THREE);
//	output_low(FOUR);
//
////	CW();
//
//   while(1){
//   
//	sensorVal = 0x7 - (PORTB & 0x7);
//	printf("value %d \r\n",sensorVal);
//	delay_ms(300);
////	putc('A');
////	delay_ms(10);
////   output_high(ZERO);
////   delay_ms(1000);
////   output_low(ZERO);
////   delay_ms(1000);
//   
//   }
//
//}
//
//void CW(){
//
//while(1){
//
//	output_high(ONE);
//	output_low(TWO);
//	output_low(THREE);
//	output_low(FOUR);
//
//	//output_high(ZERO);
//	delay_ms(StepDly);
//
//	output_low(ONE);
//	output_high(TWO);
//	output_low(THREE);
//	output_low(FOUR);
//
//	//output_low(ZERO);
//	delay_ms(StepDly);
//
//	output_low(ONE);
//	output_low(TWO);
//	output_high(THREE);
//	output_low(FOUR);
//
//	//output_high(ZERO);
//	delay_ms(StepDly);
//
//	output_low(ONE);
//	output_low(TWO);
//	output_low(THREE);
//	output_high(FOUR);
//
//	//output_low(ZERO);
//	delay_ms(StepDly);
//
//
//
//}
//
//}