#include "sensor.h"
#include "debug.h"

void
ulterSetup(const int port[][2])
{
    for(int i=0; i<=2; i++)
    {
        pinMode(port[i][0],OUTPUT);
        pinMode(port[i][1],INPUT);
    }
}

float
ulterDistance(const int * port)
{
    //定义端口
    int TRIG = port[0];
    int ECHO = port[1];
    //定义变量
    float waitTime;
    float distance;
    //TRIG 发送信号
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG,HIGH);
    delayMicroseconds(10);
    // 等待回声
    waitTime = float(pulseIn(ECHO, HIGH, 30000));//time 
    // 计算距离
    distance = (waitTime * 17)/1000;
#ifdef DEBUG
    Serial.print(distance);
    Serial.print("cm");
#endif
    return distance;
}
