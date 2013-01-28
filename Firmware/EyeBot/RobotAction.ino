#include <Servo.h>
#include "EyeBot.h"
#include "ServoMotor.h"
#include "RobotAction.h"



void surprise()
{
  standingHome();
  setSpeed(1);
  moveDualServo(footL,footR,-30,30);
  revertSpeed();
  delay(1000);
  standingHome();
  delay(200);
  setSpeed(2);
  goBackward(1);
  revertSpeed();
  resetFreneticWatchdog(); 
  
}

void frenetic(int step)
{
  for(int i=0; i<step; i++) {
    moveDualServo(footL,footR,18,18);
    moveDualServo(footL,footR,-18,-18);
    delay(speed*random(1,10));
    moveDualServo(footL,footR,-18,-18);
    moveDualServo(footL,footR,18,18);
  }
}

void goBackward(int step) 
{
   for(int i=0; i<step; i++) {
     BackFootR();
     delay(speed*2);
     BackFootL();
     resetFreneticWatchdog(); 
   }
}
 

void BackFootR()
{
   moveSingleServo(footR,5); // ruoto gamba destra verso l'esterno per favoririe il bilanciamento per l'inclinazione verso sinistra
   moveDualServo(footR,footL,45,30); // inclino verso sinistra mentre continuo a ruotare la gamba destra verso l'esterno
   moveDualServo(footR,footL,-20,20); // continuo ad inclinare verso sinistra mentre ruoto la gamba destra verso l'interno
   moveDualServo(shoulderR,shoulderL,33,33); //avanzo in avanti parallelamente con la coscia destra e sinistra 
   moveDualServo(footR,footL,-30,-50); //riporto entrambe le gambe in posizione 0
   resetFreneticWatchdog(); 
}

void BackFootL()
{
   moveSingleServo(footL,-5);
   moveDualServo(shoulderL,footR,-10,-10);
   moveDualServo(footL,footR,-45,-20);
   moveDualServo(footL,footR,20,-10);
   moveDualServo(shoulderL,shoulderR,-23,-33);
   moveDualServo(footL,footR,30,40);  
   resetFreneticWatchdog(); 
}
void caress() 
{
  moveDualServo(footR,footL,25,-25);
  delay(speed*2);
 
  do {
    int shoulder_random=randomFoot();  
    for(int i=0; i<2; i++) {
      if(shoulder_random==R) {
        moveSingleServo(shoulderR,-30);
        delay(speed*2);
        moveSingleServo(shoulderR,30);
      }else {
        moveSingleServo(shoulderL,30);
        delay(speed*2);
        moveSingleServo(shoulderL,-30);
      }
    }
  }  while(checkTouch());
 // standingHome();
  //frenetic(2);
  
  moveDualServo(footR,footL,-25,25);
  resetFreneticWatchdog(); 
 
}
void ForwardFootR() 
{
   moveSingleServo(footR,5); // ruoto gamba destra verso l'esterno per favoririe il bilanciamento per l'inclinazione verso sinistra
   moveDualServo(footR,footL,45,30); // inclino verso sinistra mentre continuo a ruotare la gamba destra verso l'esterno
   moveDualServo(footR,footL,-20,20); // continuo ad inclinare verso sinistra mentre ruoto la gamba destra verso l'interno
   moveDualServo(shoulderR,shoulderL,-33,-33); //avanzo in avanti parallelamente con la coscia destra e sinistra 
   moveDualServo(footR,footL,-30,-50); //riporto entrambe le gambe in posizione 0
   resetFreneticWatchdog(); 
}

void ForwardFootL() 
{
   moveSingleServo(footL,-5);
   moveDualServo(shoulderL,footR,10,-10);
   moveDualServo(footL,footR,-45,-20);
   moveDualServo(footL,footR,20,-10);
   moveDualServo(shoulderL,shoulderR,23,33);
   moveDualServo(footL,footR,30,40);
   resetFreneticWatchdog(); 
}

void rush(int step) 
{
  setSpeed(2);
  for(int i=0; i<step; i++)
     goForward(1);
  revertSpeed();
  delay(200);
  resetFreneticWatchdog(); 
}


void rotateR()
{
   moveSingleServo(footR,5); // ruoto gamba destra verso l'esterno per favoririe il bilanciamento per l'inclinazione verso sinistra
   moveDualServo(footR,footL,45,30); // inclino verso sinistra mentre continuo a ruotare la gamba destra verso l'esterno
   moveDualServo(footR,footL,-20,20); // continuo ad inclinare verso sinistra mentre ruoto la gamba destra verso l'interno
   moveSingleServo(shoulderR,-33); //avanzo in avanti parallelamente con la coscia destra e sinistra 
   moveDualServo(footR,footL,-30,-50); //riporto entrambe le gambe in posizione 0
 
   moveSingleServo(footL,-5);
   moveSingleServo(footR,-10);
   moveDualServo(footL,footR,-45,-20);
   moveDualServo(footL,footR,20,-10);
   moveSingleServo(shoulderR,33);
   moveDualServo(footL,footR,30,40);
   resetFreneticWatchdog();   
}

void rotateL()
{
   moveSingleServo(footR,5); // ruoto gamba destra verso l'esterno per favoririe il bilanciamento per l'inclinazione verso sinistra
   moveDualServo(footR,footL,45,30); // inclino verso sinistra mentre continuo a ruotare la gamba destra verso l'esterno
   moveDualServo(footR,footL,-20,20); // continuo ad inclinare verso sinistra mentre ruoto la gamba destra verso l'interno
   moveSingleServo(shoulderL,-33); //avanzo in avanti parallelamente con la coscia destra e sinistra 
   moveDualServo(footR,footL,-30,-50); //riporto entrambe le gambe in posizione 0
   
   moveSingleServo(footL,-5);
   moveDualServo(shoulderL,footR,10,-10);
   moveDualServo(footL,footR,-45,-20);
   moveDualServo(footL,footR,20,-10);
   moveSingleServo(shoulderL,23);
   moveDualServo(footL,footR,30,40);
   resetFreneticWatchdog(); 
}
  
void goForward(int step) 
{
   for(int i=0; i<step; i++) {
     ForwardFootR();
     delay(speed*2);
     ForwardFootL();
   }
   resetFreneticWatchdog(); 
}
 
void standingHome()
{
  shoulderR.write(HOME_SR);
  shoulderL.write(HOME_SL); 
  footL.write(HOME_FL);
  footR.write(HOME_FR);
  resetFreneticWatchdog(); 
}

void fearNoise()
{
  if(checkNoise() ) {
   SERIAL_ECHO("Fear Noise");
   surprise();
   delay(400);
  }
}

void adorablePet()
{
  if(checkTouch()) {
    SERIAL_ECHO("adorable Pet");
    caress();
  }
}

void freneticWatchDog()
{
  if(millis()-time> FRENETIC_TIMEOUT ) {
    frenetic(3);
    resetFreneticWatchdog();
  }
}

void resetFreneticWatchdog()
{
  time=millis();
  Serial.println("Reset");
}

void greet() 
{
  setSpeed(3); 
  
  if(randomFoot()==L) {
    moveSingleServo(footL,-5);
    moveDualServo(footL,footR,-45,-35);
    moveDualServo(footL,footR,20,-20);
    revertSpeed();
    setSpeed(1);
    for(int i=0; i<3; i++) {
      moveSingleServo(shoulderL,30);
      delay(200);
      moveSingleServo(shoulderL,-30);
      delay(200);
    }
    delay(random(300,400));
    revertSpeed();
    moveDualServo(footL,footR,30,55);
  }
  else {
    moveSingleServo(footR,5);
    moveDualServo(footR,footL,45,35);
    moveDualServo(footR,footL,-20,20);
    revertSpeed();
    setSpeed(1);
    for(int i=0; i<3; i++) {
      moveSingleServo(shoulderR,-30);
      delay(200);
      moveSingleServo(shoulderR,30);
      delay(200);
    }
    delay(random(300,400));
    revertSpeed();
    moveDualServo(footR,footL,-30,-55);
  }

  
  
}
