
#ifndef servomotor_h
#define servomotor_h

void servoInit();
void moveDualServo( Servo s1,Servo s2,int val1,int val2);
void moveSingleServo( Servo s, int val);
void servoMotor(int state);
void setSpeed(int s);
void revertSpeed();

#endif
