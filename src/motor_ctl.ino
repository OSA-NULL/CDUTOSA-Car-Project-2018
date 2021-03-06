#include "motor_ctl.h"

void
motorControl(const int* port, direction_t direction)
{
    int direction_arr[][4] = {
        {128,   0, 128,   0},
        {  0, 128,   0, 128},
        {  0, 128, 128,   0},
        {128,   0,   0, 128},
        {  0,   0,   0,   0},
    };

    for(int i = 0; i <= 3; i++){
        analogWrite(port[i], direction_arr[direction][i]);
    }
}

