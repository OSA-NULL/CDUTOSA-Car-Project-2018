#include "motor_ctl.h"
#include "ultrasound.h"

//小车端口
int port[] = {5, 6, 10, 11};
//前后左右
//建议不要设置整体值太大
int forward[] = {128, 0, 128, 0};
int back[] = {0, 128, 0, 128};
int left[] = {0, 128, 128, 0};
int right[] = {128, 0, 0, 128};
int stack[] = {0, 0, 0, 0};
void setup() {
    motorSetup(port);
}

void loop() {

}
