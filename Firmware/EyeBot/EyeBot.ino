#include <Servo.h>

#include "EyeBot.h"
#include "RobotAction.h"
#include "ServoMotor.h"
#include "Sensors.h"

void setup() 
{
  MYSERIAL.begin(9600);
  //Init Servo
  servoInit();
  sensorsInit();
  standingHome();
  greet();
  servoMotor(OFF);
  time=millis();
}


void loop()
{  
  fearNoise();
  adorablePet();
  freneticWatchDog();
}

void parseCmd(char cmd)
{  
  if(cmd == 'G') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Go Forward");
    goForward(1);
    servoMotor(OFF);  
  }
  
    if(cmd == 'g') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Greet");
    greet();
    servoMotor(OFF);  
  }
  
  if(cmd == 'B') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Back");
    goBackward(1);
    servoMotor(OFF);   
  }
  
  else if( cmd == 'H') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Home");
    standingHome();
    servoMotor(OFF );  
  }
  
    else if( cmd == 'S') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Surprise");
    surprise() ;
    servoMotor(OFF);
  }
    
  else if( cmd == 'R') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Rotate Right");
    rotateR();
    servoMotor(OFF );  
  }
  
    else if( cmd == 'L') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Rotate Left");
    rotateL();
    servoMotor(OFF );  
  }
  
  else if( cmd == 'C') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Caress");
    caress();
    servoMotor(OFF );  
  }
    else if( cmd == 'F') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Frenetic");
    frenetic(4);
    servoMotor(OFF );  
  }
  else if( cmd == 'r') 
  {
    servoMotor(ON);
    SERIAL_ECHO("Rush");
    rush(3);
    servoMotor(OFF );  
  }
  
  else if( cmd == 'h') 
  {
    SERIAL_ECHO("Help:");
    SERIAL_ECHO("\tG\tGo Forward");
    SERIAL_ECHO("\tB\tGo Backward ");
    SERIAL_ECHO("\tH\tGo Home");
    SERIAL_ECHO("\tS\tSurprise");
    SERIAL_ECHO("\tg\tGreet");
    SERIAL_ECHO("\tL\tLeft Turn");
    SERIAL_ECHO("\tR\tRight Turn");
    SERIAL_ECHO("\tC\tCaress");
    SERIAL_ECHO("\tr\tRush");
    SERIAL_ECHO("\tF\tFrenetic");
  }
}


void serialEvent()
{
  while(MYSERIAL.available()>0)
  {
    cmd_buff[buff_index] = (char)MYSERIAL.read();
    if(cmd_buff[buff_index] == '\n')
    {
       cmd_buff[buff_index] = 0;
       parseCmd(cmd_buff[0]);
       buff_index = 0;
    } else
       buff_index++;
    if(buff_index >= BUFFLEN)
    {
      buff_index = BUFFLEN-1;
    }
  }
}

