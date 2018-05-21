#ifndef __ultrasound_h__
#define __ultrasound_h__

#include <Arduino.h>

inline void
ultraSetup(int* port)
{
    pinMode(port[0],OUTPUT);
    pinMode(port[1],INPUT);
}
/*
 * float distance(int* port)
 * 功能：
 *     通过超声波模块计算距离
 * 参数：
 *     port:超声波控制端口数组 为[Trig, Echo]
 * 返回：
 *     厘米单位距离
 */
inline float
distance(int* port)
{
    int Trig = port[0];
    int Echo = port[1];

    digitalWrite(Trig, LOW); //给Trig发送一个低电平    
    delayMicroseconds(2);        //等待 2微妙    
    digitalWrite(Trig,HIGH); //给Trig发送一个高电平    
    delayMicroseconds(10);        //等待 10微妙    
    digitalWrite(Trig, LOW); //给Trig发送一个低电平    

        
    return (float(pulseIn(Echo, HIGH)) * 17) / 1000;
}
     
#endif // __ultrasounds_h__
