#include "motor_ctl.h"
#include "stdio.h"
#include "sensor.h"
#include "debug.h"

//小车马达端口 [右前，右后，左前，左后]
const int motorPort[] = {10, 11, 5, 6};
//小车测距端口 [Trig(前，左，右), Echo(前，左，右)]
const int ulterPort[][3] = {
    { 7, 8, 9},
    {A1, 3, 2}
};
//小车测光端口 [输入]
const int senPort = A0;
//小车的状态
extern unsigned long stateTime[2][3];

void setup()
{
#ifdef DEBUG
    serial.begin(9600);
#endif
    motorSetup(motorPort);   //初始化马达端口
    ulterSetup(ulterPort);   //初始化超声波端口
    senSetup(senPort);       //初始化光敏电阻端口
    for(int i=0; i<=2; i++)  //发射信号
      ulterSend(i);
}

void loop()
{
  stateTime[RECEIVE][0] = float(pulseIn(ulterPort[0][0], HIGH)); //等待前方信号
#ifdef DEBUG
  serial.println("Here is statetime");
  for (int i=0; i<2; i++){
    for(int j=0; j<3; j++)
      serial.print(stateTime[i][j]);
    serial.println();
  }
#endif
  if((stateTime[SEND][0]-stateTime[RECEIVE][0]) > 600)
    motorControl(motorPort, FORWARD);
  else if((stateTime[SEND][1]-stateTime[RECEIVE][1]) < 600)
    motorControl(motorPort, RIGHT);
  else if((stateTime[SEND][2]-stateTime[RECEIVE][2]) < 600)
    motorControl(motorPort, LEFT);
  else
    motorControl(motorPort, FORWARD);
}
