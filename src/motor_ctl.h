#ifndef __MOTOR_CTL_H__
#define __MOTOR_CTL_H__

#include <Arduino.h>

enum Directions{
    FORWARD, BACK, RIGHT, LEFT, PARK, CRAZY
};
typedef enum Directions  direction_t;

/*
 * void motorControl(int* port, int* degree)
 * 功能：
 *     控制小车动作
 * 参数：
 *     port:小车控制端口数组 为[右前，右后，左前，左后]
 *     degree：控制幅度(PWM值)(0~255)
 * 返回：
 *     无
 */
void
motorControl(const int* port, direction_t direction);

/*
 * void motorSetup(int port[])
 * 功能：
 *     初始化小车电机控制端口
 * 参数：
 *     port:小车控制端口数组 为[右前，右后，左前，左后]
 * 返回：
 *     无
 */
inline void 
motorSetup(const int* port)
{
    int i = 0;
    for(; i < 4; i++){
        pinMode(port[i], INPUT);
    }
}
/*
 * void forward
 */

#endif // __MOTOR_CTL_h__
