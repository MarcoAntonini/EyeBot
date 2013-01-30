#include "EyeBot.h"
#include "CapacitiveSensor.h"

CapacitiveSensor cap_sens = CapacitiveSensor(CAP_SENS_READ_PIN,CAP_SENS_FOIL_PIN);  


void sensorsInit()
{
 cap_sens.set_CS_AutocaL_Millis(0xFFF);
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

