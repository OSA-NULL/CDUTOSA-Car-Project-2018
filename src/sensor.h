#ifndef __sensor_h__
#define __sensor_h__

#include <Arduino.h>

/***************************************************************
 * ultrasound    超声波模块
 **************************************************************/

/*
 * void ultraSetup(int* port)
 * 功能:
 *     初始化超声波端口
 * 参数：
 *     port:超声波控制端口数组 为[Trig, Echo1,Echo2,Echo3]
 * 返回:
 *     无
 */
void ulterSetup(int* port);
/*
 * void distancealternate(int* port,float* distance);
 * 功能：
 *     通过超声波模块计算距离
 * 参数：
 *     port:超声波控制端口数组 为[端口号, 距离]
 * 返回：
 *     无
 */
void distanceAlternate(int* port,float* distance);
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
