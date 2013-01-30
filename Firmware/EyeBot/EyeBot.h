#ifndef eyebot_h
#define eyebot_h

#define BUFFLEN 10
#define MYSERIAL Serial

/********  Pinout Configuration *********/

#define SR_PIN 8   //Shoulder Right on Pin 8
#define SL_PIN 10  //Shoulder Left on Pin 10
#define FR_PIN 9   //Foot Right on Pin 9
#define FL_PIN 11  //Foot Left on Pin 11

#define SERVO_PWR_PIN 7 
#define MIC_PIN 5 // preamp Mic on analog 0

#define CAP_SENS_FOIL_PIN 2
#define CAP_SENS_READ_PIN 4

/********  Servo Configuration *********/

#define HOME_SR 60 
#define HOME_SL 90
#define HOME_FR 100
#define HOME_FL 80

/********  Sensors Configuration *********/

#define NOISE_THRESHOLD 400
#define TOUCH_THRESHOLD 200

#define FRENETIC_TIMEOUT 300000 //every 5 minutes of inactivity

/********  Utils Constant *********/

#define ON 0
#define OFF 1

#define L 0
#define R 1

#define SERIAL_DEBUG

#ifdef SERIAL_DEBUG
#define SERIAL_ECHO(x) MYSERIAL.println(x)
#endif

/********  Global Vars *********/

Servo shoulderL; //Servo Shoulder Left Object
Servo shoulderR; //Servo Shoulder Right Object
Servo footL;     //Servo Foot Left Object
Servo footR;     //Servo Foot Right Object

int speed=4;  //Servo speed of movement
int old_speed=4; //Stored old speed

char cmd_buff[BUFFLEN];
int buff_index;

unsigned long time;

#endif
