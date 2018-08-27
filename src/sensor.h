#ifndef __sensor_h__
#define __sensor_h__
#define SEND 0
#define RECEIVE 1

#include <Arduino.h>

/***************************************************************
 * ultrasound    超声波模块
 **************************************************************/
/*
 * void ultraSent(int Trig)
 * 功能:
 *     发送超声波信号
 * 参数：
 *     Trig:超声波发送端口
 * 返回:
 *     无
 */

void ulterSend(int Trig);
/*
 * void ultraSetup(int port[][3])
 * 功能:
 *     初始化超声波端口
 * 参数：
 *     port:超声波控制端口数组 为[[Trig], [Echo]]
 * 返回:
 *     无
 */
void ulterSetup(int port[][3]);
/*
 * void distancealternate(int echo);
 * 功能：
 *     利用中断来改变状态；
 * 参数：
 *     Echo:超声波接受端口数组
 * 返回：
 *     无
 */
void stateAlternate(int echo);
/***************************************************************
 *sensitization    光敏电阻模块
 **************************************************************/

/*
 * void senSetup(int* port, float* distance)
 * 功能:
 *     初始化光敏电阻端口
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
