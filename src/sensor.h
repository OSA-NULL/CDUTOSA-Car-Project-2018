#ifndef __sensor_h__
#define __sensor_h__
#include <Arduino.h>

/*
 * void ultraSetup(int port[][3])
 * 功能:
 *     初始化超声波端口
 * 参数：
 *     port:超声波控制端口数组 为[[前], [左],[右]]
 * 返回:
 *     无
 */
void ulterSetup(const int port[][2]);
/*
 * float ulterDistance(int echo);
 * 功能：
 *     输出：超声波距离
 * 参数：
 *      port:单个超声波模块端口
 * 返回：
 *     障碍物距离（cm）
 */
float ulterDistance(const int * port);
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
senSetup(const int port)
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
senLight(const int port)
{
    return(analogRead(port));
}


#endif // __sensor_h__
