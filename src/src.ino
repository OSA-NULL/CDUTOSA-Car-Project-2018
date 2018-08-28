#include "motor_ctl.h"
#include "stdio.h"
#include "sensor.h"
#include "debug.h"

//小车马达端口 [右前，右后，左前，左后]
int motorPort[] = {10, 11, 5, 6};
//小车测距端口 [Trig(前，左，右), Echo(前，左，右)]
int ulterPort[][2] = {
    {7, A1},
    {8, 3},
    {9, 2},
};
//小车测光端口 [输入]
int senPort = A0;

void setup()
{
#ifdef DEBUG
    Serial.begin(9600);
#endif
    motorSetup(motorPort);   //初始化马达端口
    ulterSetup(ulterPort);   //初始化超声波端口
    senSetup(senPort);       //初始化光敏电阻端口
}

void loop()
{
    //定义端口
    int * UFRONT = ulterPort[0];
    int * ULEFT = ulterPort[1];
    int * URIGHT = ulterPort[2];

    //事件树
    if (ulterDistance(UFRONT) < 10)
    {
#ifdef DEBUG
        Serial.println("Go forward");
#else
        motorControl(motorPort, PARK);
#endif
        if (ulterDistance(ULEFT) < 10)
        {
            if (ulterDistance(UFRONT) < 10)
#ifdef DEBUG
                Serial.println("Oh, I am back");
#else
                motorControl(motorPort, BACK);
#endif
            else
#ifdef DEBUG
                Serial.println("Turn right now");
#else
                motorControl(motorPort, RIGHT);
#endif
        }
        else
#ifdef DEBUG
            Serial.println("Turn left now");
#else
            motorControl(motorPort, LEFT);
#endif
    }
    else
        motorControl(motorPort, FORWARD);
}
