#ifndef __MOTOR_CTL_H__
#define __MOTOR_CTL_H__

 /*
  * void motorControl(int* port, int times, int* degree)
  * 功能：
  *     控制小车动作
  * 参数：
  *     port:小车控制端口数组 为[右前，右后，左前，左后]
  *     times:动作持续时间
  *     degree：控制幅度(PWM值)(0~255)
  * 返回：
  *     无
  */
typedef enum {
    FORWARD, BACK, LEFT, RIGHT, PARK
} direction_t;
void
motorControl(int* port, int times, direction_t direction);

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
motorSetup(int* port)
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
