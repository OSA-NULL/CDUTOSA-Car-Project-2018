#include "motor_ctl.h"
#include "stdio.h"
#include "sensor.h"

//小车马达端口 [右前，右后，左前，左后]
const int motorPort[] = {10, 11, 5, 6};
//小车测距端口 [Trig, Echo]
const int ulterPort[]={2,A1,A2,A3};
//小车测光端口 [输入]
const int senPort = A0;

void setup()
{
    motorSetup(motorPort);  //初始化马达端口
    ulterSetup(ulterPort);  //初始化超声波端口
    senSetup(senPort);//初始化光敏电阻端口
}

void loop()
{
    float distance[]={0,0,0};//初始化状态
    
    distanceAlternate(ulterPort, distance);
    
    if(senLight(senPort) > 300)
        motorControl(motorPort, 200, BACK);
    else if(distance[0] < 25)
         if(distance[1] <25 && distance[2] >25)
            motorControl(motorPort, 200, LEFT);
         else if(distance[2] <25 && distance[1] >25)
            motorControl(motorPort, 200, RIGHT);
         else 
            motorControl(motorPort, 200, BACK);
    else
         motorControl(motorPort, 200, FORWARD);
}


