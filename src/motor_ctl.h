#ifndef __MOTOR_CTL_H__
#define __MOTOR_CTL_H__
/*
 * void portSetup(int port[])
 * 功能：
 *   初始化小车电机控制端口
 * 参数：
 *   port:小车控制端口数组 为[右前，右后，左前，左后]
 * 返回：
 *   无
 */
 /*
  * void control(int* port, int times, int* degree)
  * 功能：
  *   控制小车动作
  * 参数：
  *   port:小车控制端口数组 为[右前，右后，左前，左后]
  *   times:动作持续时间
  *   degree：控制幅度(PWM值)(0~255)
  * 返回：
  *   无
  */

//端口初始化
void portSetup(int* port) {
int i = 0;
for(; i < 4; i++){
  pinMode(port[i], INPUT);
}
};
//状态控制
void control(int* port, int times, int degree[]){
  analogWrite(port[0], degree[0]);
  analogWrite(port[1], degree[1]);
  analogWrite(port[2], degree[2]);
  analogWrite(port[3], degree[3]);

  delay(times);
};
#endif
