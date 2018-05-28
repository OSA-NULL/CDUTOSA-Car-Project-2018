#include "motor_ctl.h"
#include "ultrasound.h"

//小车马达端口 [右前，右后，左前，左后]
int motorPort[] = {5, 6, 10, 11};
//小车测距端口 [Trig, Echo]
int ultraPort[] = {2,3};
//小车测光端口 [输入]
int photoSensitive = A0;

void setup() {
    motorSetup(motorPort);  //初始化马达端口
    ultraSetup(ultraPort);  //初始化超声波端口
    pinMode(photoSensitive, INPUT);
}

void loop() {
    if(distance(ultraPort) >= 25)
        motorControl(motorPort, 300, FORWARD);
    else
        motorControl(motorPort, 200, BACK); 
    if(photoSensitive < 300)
        motorControl(motorPort, 200, BACK); 
}
