#include "motor_ctl.h"
#include "stdio.h"
#include "sensor.h"
void Back(void);

//小车马达端口 [右前，右后，左前，左后]
int motorPort[] = {10, 11, 5, 6};
//小车测距端口 [Trig, Echo]
int ultraPort[] = {2,A1};
//小车测光端口 [输入]
int senPort = A0;

void setup() {
    motorSetup(motorPort);  //初始化马达端口
    ultraSetup(ultraPort);  //初始化超声波端口
    senSetup(senPort);//初始化光敏电阻端口
}

void loop() {
    if(distance(ultraPort) >= 25)
        if(senLight(senPort) < 300)
            motorControl(motorPort, 200, FORWARD);
        else
            motorControl(motorPort, 200, BACK);
    else
            motorControl(motorPort, 200, BACK);
}


