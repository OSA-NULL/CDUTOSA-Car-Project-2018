#include "motor_ctl.h"
#include "stdio.h"
#include "sensor.h"
#include "debug.h"

//小车马达端口 [右前，右后，左前，左后]
const int motorPort[] = {10, 11, 5, 6};
//小车测距端口 [Trig(前，左，右), Echo(前，左，右)]
const int ulterPort[][2] = {
    {7, A1},
    {8, 3},
    {9, 2},
};
//小车测光端口 [输入]
const int senPort = A0;

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
    const int * UFRONT = ulterPort[0];
    const int * ULEFT = ulterPort[1];
    const int * URIGHT = ulterPort[2];

    float d_ufront = 0;
    float d_uright = 0;
    float d_uleft = 0;
    //测距
    d_ufront= ulterDistance(UFRONT);
    d_uright = ulterDistance(URIGHT);
    d_uleft = ulterDistance(ULEFT);
    //事件树
    motorControl(motorPort, PARK);
    if (d_ufront < 15.0 )
    {
        if(d_uleft < 15.0 && d_uright < 15.0)
        {
            motorControl(motorPort, BACK);
            delay(500);
        }
        else if(d_uleft < d_uright)
              {
                  motorControl(motorPort, RIGHT);
                  delay(500);
              }
              else
              {
                  motorControl(motorPort, LEFT);
                  delay(500);
              }
    }
    if (d_uleft < 15.0)
    {
        motorControl(motorPort, RIGHT);
        delay(500);
    }
    if (d_uright < 15.0)
    {
        motorControl(motorPort, LEFT);
        delay(500);
    }
    motorControl(motorPort, FORWARD);

}
