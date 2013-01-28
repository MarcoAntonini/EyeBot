#include "EyeBot.h"
#include "CapacitiveSensor.h"

CapacitiveSensor cap_sens = CapacitiveSensor(4,2);  
//CapacitiveSensor cap_sens_eye = CapacitiveSensor(4,5);   


void sensorsInit()
{
 cap_sens.set_CS_AutocaL_Millis(0xFFF);
 //cap_sens_eye.set_CS_AutocaL_Millis(0xFFF);
 pinMode(MIC_PIN,INPUT);
}

boolean checkNoise() 
{
 
  if(analogRead(MIC_PIN) > NOISE_THRESHOLD ) {
    return(true);
  }
  else
    return(false);
}

boolean checkTouch()
{
  long val=cap_sens.capacitiveSensor(20);
  
  if(val > TOUCH_THRESHOLD )
    return(true);
  else
    return(false);
}

