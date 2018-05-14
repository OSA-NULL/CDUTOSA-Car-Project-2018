#ifndef __MOTOR_CTL_H__
#define __MOTOR_CTL_H__
//初始化电机控制口

//右侧电机
int rinput1= 2;
int rinput2= 3;
int rinput3= 4;
int rinput4= 5;
//左侧电机
int linput1= 8;
int linput2= 9;
int linput3= 10;
int linput4= 11;

//停止代码
void takebreak(int times){
//左侧
  digitalWrite(linput2,LOW);
  digitalWrite(linput1,LOW);
  digitalWrite(linput4,LOW);
  digitalWrite(linput3,LOW);
//右侧
  digitalWrite(rinput2,LOW);
  digitalWrite(rinput1,LOW);
  digitalWrite(rinput4,LOW);
  digitalWrite(rinput3,LOW);
//延时
  delay(times);
}
//前进代码
void forward(int times){
//左侧
  digitalWrite(linput1,HIGH);
  digitalWrite(linput2,LOW);
  digitalWrite(linput3,HIGH);
  digitalWrite(linput4,LOW);
//右侧
  digitalWrite(rinput1,HIGH);
  digitalWrite(rinput2,LOW);
  digitalWrite(rinput3,HIGH);
  digitalWrite(rinput4,LOW);
//延时
  delay(times);
}

//后退代码
void backward(int times){
//左侧
  digitalWrite(linput2,HIGH);
  digitalWrite(linput1,LOW);
  digitalWrite(linput4,HIGH);
  digitalWrite(linput3,LOW);
//右侧
  digitalWrite(rinput2,HIGH);
  digitalWrite(rinput1,LOW);
  digitalWrite(rinput4,HIGH);
  digitalWrite(rinput3,LOW);
//延时
  delay(times);
}

//左转代码
void toleft(int times){
//左侧
  digitalWrite(linput2,HIGH);
  digitalWrite(linput1,LOW);
  digitalWrite(linput4,HIGH);
  digitalWrite(linput3,LOW);
//右侧
  digitalWrite(rinput1,HIGH);
  digitalWrite(rinput2,LOW);
  digitalWrite(rinput3,HIGH);
  digitalWrite(rinput4,LOW);
//延时
  delay(times);
}

//右转代码
void toright(int times){
//左侧
  digitalWrite(linput1,HIGH);
  digitalWrite(linput2,LOW);
  digitalWrite(linput3,HIGH);
  digitalWrite(linput4,LOW);
//右侧
  digitalWrite(rinput2,HIGH);
  digitalWrite(rinput1,LOW);
  digitalWrite(rinput4,HIGH);
  digitalWrite(rinput3,LOW);
//延时
  delay(times);
}

//端口初始化
void portsetup() {
int i=0;
for(i=2; i<6; i++){
  pinMode(i,OUTPUT);
}
for(i=8; i<12; i++){
  pinMode(i,OUTPUT);
}
}

#endif
