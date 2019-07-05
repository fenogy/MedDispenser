

void HwPutc(char c);                     

int8 hwTxFIFO[30];                                                 
int8 hwRxFIFO[16]; 
                                           
int8 hwTxStatus         = 0; 
int8 hwRxStatus         = 0;
int8 hwTxPointer        = 0;  
 
#BYTE  HWRXREG            =  0x0FAE  
#BYTE  HWTXREG            =  0x0FAD
                      

#int_RDA 
void  RDA_isr(void)                      
{                                  
  hwRxFIFO[hwRxStatus] = HWRXREG;
                                                                         
  hwRxStatus++;
  HwPutc(HWRXREG); 
  if(hwRxStatus>79){
     hwRxStatus=0;
  }
               
   clear_interrupt(INT_RDA);
                                                     
}    

#INT_TBE 
void TBE_isr()
{   

    HWTXREG       = hwTxFIFO[hwTxPointer]; 
                                             				// I added this
    hwTxStatus --; 
    hwTxPointer++;  

    hwTxStatus    &= 0x0F;
                               
    enable_interrupts(INT_TBE);                            // Enable interrupts again

    if(!hwTxStatus)
    {
    disable_interrupts(INT_TBE);         
    }                                  
}                       

void HwSerialTxFIFO(char *data, int8 length)
{   int8 i;
    for(i = 0;i < length;i++)
   {                           
      hwTxFIFO[i] = data[i];
   } 
   hwTxStatus       = length; 
   hwTxPointer       = 0;
   
   enable_interrupts(INT_TBE); 

}


void HwPutc(char c){

   HwSerialTxFIFO(&c,1);

}
