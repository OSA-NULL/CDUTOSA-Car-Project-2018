#include "motor_ctl.h"

//小车端口
int port[] = {5, 6, 10, 11};
//前后左右
int forward[] = {255, 0, 255, 0};
int back[] = {0, 255, 0, 255};
int left[] = {0, 255, 255, 0};
int right[] = {255, 0, 0, 255};

void setup() {
    portsetup(port);
}

void loop() {
  control(port, 5000, forward);
  control(port, 2000, left);
}
