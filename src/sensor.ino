#include "sensor.h"

void 
ulterSetup(int* port)
{
    pinMode(port[0],OUTPUT);
    for(int i=1; i <= 3; i++){
        pinMode(port[i],INPUT); 
    }
}

void
distanceAlternate(int* port,float* distance)
{
    int Trig = port[0];
    for(int i=1; i<=3; i++){
        digitalWrite(Trig, LOW); //给Trig发送一个低电平
        delayMicroseconds(2);        //等待 2微妙
        digitalWrite(Trig,HIGH); //给Trig发送一个高电平
        delayMicroseconds(10);        //等待 10微妙
        digitalWrite(Trig, LOW); //给Trig发送一个低电平
        distance[i-1]= (float(pulseIn(port[i], HIGH)) * 17) / 1000;
    }
}
