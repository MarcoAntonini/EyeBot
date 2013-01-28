#include <Servo.h>
#include "EyeBot.h"
#include "ServoMotor.h"

/** servoMotor **/
// Power ON/OFF all servo motor
void servoMotor(int state)
{
  if(state==ON)
    digitalWrite(SERVO_PWR_PIN,HIGH);
  else if(state==OFF)
    digitalWrite(SERVO_PWR_PIN,LOW);
}

/** servoInit **/
// Init Servo object
void servoInit()
{
  pinMode(SERVO_PWR_PIN,OUTPUT); //init Servo PWR PIN
  servoMotor(ON);
  shoulderL.attach(SL_PIN);
  shoulderR.attach(SR_PIN);
  footL.attach(FL_PIN);
  footR.attach(FR_PIN);
  servoMotor(OFF);
}

/** randomFoot **/
// return random Left or Right
int randomFoot() {
  if(random(0,2))
    return(L);
  else
    return(R);
}

/** moveDualServo **/
// Moves two servo simultaneously by one degree at a time.
// Movements are incremental, accept negative angle
void moveDualServo( Servo s1,Servo s2,int val1,int val2)
{
  int inc1=1;
  int inc2=1;

  if(val1<0)
    inc1=-1;
  if(val2<0)
    inc2=-1;

  if(abs(val1)>abs(val2)) {
    int diff=abs(val1)-abs(val2);
    for(int i=0; i<abs(val2); i++) {
      s1.write(s1.read()+inc1);
      delay(speed);
      s2.write(s2.read()+inc2);
      delay(speed);
    }
    for(int i=0; i<diff; i++) {
      s1.write(s1.read()+inc1);
      delay(speed*2);
    }

  } 
  else if(abs(val2)>abs(val1)) {
    int diff=abs(val2)-abs(val1);
    for(int i=0; i<abs(val1); i++) {
      s1.write(s1.read()+inc1);
      delay(speed);
      s2.write(s2.read()+inc1);
      delay(speed);
    }
    for(int i=0; i<diff; i++) {
      s2.write(s2.read()+inc2);
      delay(speed*2);
    }
  } 
  else {
    for(int i=0; i<abs(val1); i++) {
      s1.write(s1.read()+inc1);
      delay(speed);
      s2.write(s2.read()+inc2);
      delay(speed);
    }
  }
}

void moveSingleServo( Servo s, int val)
{
  int inc=1;
  if(val<0)
    inc=-1;

  for(int i=0; i<abs(val); i++) {
    s.write(s.read()+inc);
    delay(speed*2);
  }
}

//Set Servo Speed
void setSpeed(int s) 
{
  if(s>=0) {
    old_speed=speed;
    speed=s;
  }
}

//Revert to old Servo Speed
void revertSpeed()
{
  speed=old_speed;
}

