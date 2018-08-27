#include "sensor.h"
#include "debug.h"

unsigned long stateTime[2][3];

void
ulterSetup(int port[][3])
{
    for(int i=0; i<=2; i++)
        pinMode(port[0][i],OUTPUT);
    pinMode(port[1][0],INPUT);
    for(int i=1; i <= 2; i++){
        pinMode(port[RECEIVE][i],INPUT_PULLUP);
//      attachInterrupt(digitalPinToInterrupt(port[RECEIVE][i]), stateAlternate, CHANGE);
    }
}

float
ulterDistance(int Trig,int Echo)
{
    float waitTime = 0;
    float distance = 0;
    //Trig 发送信号
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig,HIGH);
    delayMicroseconds(10);
    // 等待回声
    waitTime = float(pulseIn(Echo, HIGH,30000));
    // 计算距离
    distance = (waitTime * 17)/1000;
#ifdef Debug
    Serial.print(distance);
    Serial.print("cm");
#endif
    return distance;
}
