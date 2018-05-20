#include "motor_ctl.h"

void
motorControl(int* port, int times, int degree[])
{
    int direction_arr[] = {
        {128, 0, 128, 0},
        {0, 128, 0, 128},
        {0, 128, 128, 0},
        {128, 0, 0, 128},
        {0, 0, 0, 0}
    };

for(int i = 0; i < 3；i++){ 
    analogWrite(port[i], degree[3]);
}
    delay(times);
}

