/*
Progam: Stepper Motion Test
Author: B. Dring
Email: bdring@buildlog.net
Date: 11/20/09
Device: 18F452
Osc: 8MHz xtal with 4x PLL
Compiler: CCS PCWH 4.042 from Customer Computer Services Inc
www.ccsinfo.com


Motion Control Test Program

This program controls a stepper motor by outputting step and direction signals.  It allows 
varying the move distance, acceleration and max speed.  All units are in steps. An external 
program needs to convert from real world units to steps.  We maintain a 32bit
current location.  So all moves can be absolute (ie move to 1000...then move back to 500)

This uses a 25Khz Pulsing Engine in the Timer2 interrupt.

On every interrupt (engine tick) an amount gets added to a distance accumulator.  Since the engine
rate is higher than any step rate we would ever see, this amount is always less than a 
step.  To avoid floating point math, this accumulator is shifted up by 24 bits.
Therefore, when the accumulator is greater than 2^24 we take a step and reduce the
accumulator by 2^24.

The amount added to the accumulator is based on the speed and acceleration.  Acceleration
and max speed numbers are calculated before the move in accumulator units per tick.  This
makes the math very simple in the engine.  On each tick, add the acceleration value 
to the current speed and add the current speed to the accumulator.  The accululator is
always positive.  It does not care about direction, just time to next step

The only other things you need to do in the engine is to stop accelerating when
you reach the max speed and decelerate at the right time.

The engine must be kept very simple so it finishes it's work WELL within it's period,
which is 1/25kHz or 40uS.


*/

#include <18F452.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES H4                       //High speed osc with HW enabled 4X PLL
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOOSCSEN                 //Oscillator switching is disabled, main oscillator is source
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES BORV20                   //Brownout reset at 2.0V
#FUSES PUT                      //Power Up Timer
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES LVP                      //Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOCPD                    //No EE protection
#FUSES NOCPB                    //No Boot Block code protection
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOEBTRB                  //Boot block not protected from table reads

#use delay(clock=32000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,errors)

#define ENGINE_RATE 25000  // be sure timer interrupt matches this
#define SPEED_OFFSET 16777216  // 2^24 The is the offset of the accumulator 2^24 units = 1 step

#define PIN_X_STEP PIN_A1     // pin corrector to step of stepper board
#define PIN_X_DIR  PIN_A2     // pin connected to direction pin of stepper board
#define DIRECTION_FORWARD 1   
#define DIRECTION_REVERSE -1 

signed int32 currentLocation;    // store current location in steps so we can use absolute moves
int32 decelLocation;             // pre-calculated point we start to decelerated
signed int8  motionDirection;     // what direction do we move 1 = fwd -1 = rev
short bEnableMotion;             // this turns on/off the 25kHz Pulse Engine
short bDecel;                    // in decel mode

int32 currentSpeed;              // current speed in accum units per engine tick
int32 accel;                     // accel rate in accum units per engine tick
int32 maxSpeed;                  // max speed in accum units per tick
int32 accumulator;

signed int32 targetLocation;     // target position in steps
 
long moveAccelSteps;             // accel rate in steps / sec /sec
long moveMaxSpeedSteps;          // max speed in steps /sec



// this is the pulsing engine...the the file header for more info
#int_TIMER2
void  TIMER2_isr(void) 
{
   // we only do anything if this motion is enabled and we are not at the target position
   if (bEnableMotion && (currentLocation != targetLocation) )
   {
      // set the current speed
      // If we are before the decel point we accelerate or coast
      // else we decel
      
      if (currentLocation == decelLocation)
         bDecel = true;
      
      if (!bDecel)
      {
         // if we are not at max speed and accel to the speed
         if (currentSpeed < maxSpeed)
         {
            currentSpeed += accel;
         }
      }
      else // decel
      {
         currentSpeed -= accel;
         if (currentSpeed <= 0) // never let it get to zero otherwise we could get stuck 
         {
            currentSpeed = accel; 
         }
      
      }
      
      accumulator += currentSpeed;
   
      //see if we have accumulated enough for a step step
      If (accumulator > SPEED_OFFSET)
      {
         
         
         currentLocation += motionDirection;
         
         
         output_high(PIN_X_STEP);  // turn on step pin
         delay_us(4);            // wait a while
         output_low(PIN_X_STEP);   // turn it off
         
         
         accumulator -= SPEED_OFFSET;
      }
      
   
   }
   else
   {
      
      bEnableMotion = false;     
   }
}


/* this is the simple "motion planner".  It does all the intesive calulations
   It calculated the acceleration per engine tick
   It calculated the max speed per engine tick
   It determines the motion direction
   It resets the current speed to 0
   
   It turns on the Pulse Engine
*/
void doMotion()
{
   float tempAccel;
   float tempMaxSpeed;
   float t;
   int32 distToTarget;
   int32 accelDist;
   
   

   distToTarget = abs(targetLocation - currentLocation); // figure out the distance we will travel on this move
   
   tempAccel = moveAccelSteps;// * stepsInch; // in steps per sec   
   tempAccel = tempAccel / (ENGINE_RATE * ENGINE_RATE);
   tempAccel = tempAccel * SPEED_OFFSET;
   accel = (int32)tempAccel;
   
   tempMaxSpeed = moveMaxSpeedSteps;
   tempMaxSpeed = (tempMaxSpeed / ENGINE_RATE) * SPEED_OFFSET;   
   maxSpeed = (int32)tempMaxSpeed;
   
   //determine Accel distance
   //     d = 1/2 a t^2
   t = (float)moveMaxSpeedSteps / (float)moveAccelSteps;
   accelDist = (moveAccelSteps / 2) * t * t;
   
   
   
   // determine the direction
   if (targetLocation > currentLocation)
   {
      motionDirection = DIRECTION_FORWARD; 
      decelLocation = currentLocation + decelLocation; 
      output_low(PIN_X_DIR);
      
     if (accelDist >= distToTarget / 2)
         decelLocation = targetLocation - distToTarget / 2;
      else
         decelLocation = targetLocation - accelDist;
      
   }
   else
   {
      motionDirection = DIRECTION_REVERSE;
      decelLocation = currentLocation - decelLocation;
      output_high(PIN_X_DIR);
      
      if (accelDist >= distToTarget / 2)
         decelLocation = targetLocation + distToTarget / 2;
      else
         decelLocation = targetLocation + accelDist;
      
   }
   
   delay_us(4); // time for direction to "take" before steps start
   
  
   bDecel = false;
    
   currentSpeed = 0; // initialize this 
   bEnableMotion = true; // all set time to move
   
}


void main()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DIV_BY_1,159,2);
   setup_timer_3(T3_INTERNAL|T3_DIV_BY_1);
   
   currentLocation = 0;
   bEnableMotion = false;
   
   
   enable_interrupts(INT_TIMER2);
   //enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   output_low(PIN_X_STEP);
   output_high(PIN_X_DIR);
    
  
   while(true)
   {
      
      moveAccelSteps = 1000;
      moveMaxSpeedSteps = 2000;
      targetLocation = 200 * 8;
      doMotion(); 
      delay_ms(2000);
      
      moveAccelSteps = 50000;
      moveMaxSpeedSteps = 20000;
      targetLocation = 0;
      doMotion();
      delay_ms(1500);
    
   }

}