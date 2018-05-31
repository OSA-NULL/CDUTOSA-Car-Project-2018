#ifndef __sensor_h__
#define __sensor_h__

#include <Arduino.h>

/***************************************************************
 * ultrasound    超声波模块
 **************************************************************/

/*
 * void ultrasetup(int* port)
 * 功能:
 *     初始化超声波端口
 * 参数：
 *     port:超声波控制端口数组 为[Trig, Echo]
 * 返回:
 *     无
 */
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

/***************************************************************
 *sensitization    光敏电阻模块
 **************************************************************/

/*
 * void ultrasetup(int* port)
 * 功能:
 *     初始化超声波端口
 * 参数：
 *     port:光敏电阻读取端口数组
 * 返回:
 *     无
 */
inline void
senSetup(int port)
{
  pinMode(port,INPUT);
}

/*
 * int senlight(int port)
 * 功能:
 *     读取光敏电阻数值
 * 参数：
 *     port:光敏电阻读取端口数组
 * 返回:
 *     光线强度测量值
 */
inline int
senLight(int port)
{
  return(analogRead(port));
}


#endif // __sensor_h__
