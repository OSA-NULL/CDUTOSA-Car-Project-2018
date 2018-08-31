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
#ifdef DEBUG
    Serial.println('park');
#else
    motorControl(motorPort, PARK); //等待命令
#endif
    if (d_ufront < 15.0 ) //前方遇阻
    {
        if(d_uleft < 15.0 && d_uright < 15.0) //左右同时受阻
        {
#ifdef DEBUG
            Serial.println('                        back');
#else
            motorControl(motorPort, BACK); //后退
            delay(500);
#endif
        }
        else if(d_uleft < d_uright) //右大于左
        {
#ifdef DEBUG
            Serial.println('                  right');
#else
            motorControl(motorPort, RIGHT); //右转
            delay(500);
#endif
        }
        else
        {
#ifdef DEBUG
            Serial.println('            left');
#else
            motorControl(motorPort, LEFT); //左转
            delay(500);
#endif
        }
    }
    if (d_uleft < 15.0) //单单左受阻
    {
#ifdef DEBUG
        Serial.println('                  right');
#else
        motorControl(motorPort, RIGHT); //右转
        delay(500);
#endif
    }
    if (d_uright < 15.0) //单单右受阻
    {
#ifdef DEBUG
        Serial.println('            left');
#else
        motorControl(motorPort, LEFT); //左转
        delay(500);
#endif
    }
#ifdef DEBUG
    Serial.println('      front');
#else
    motorControl(motorPort, FORWARD); //前进
#endif
}
