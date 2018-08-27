#include "sensor.h"

unsigned long stateTime[2][3];

void
ulterSetup(int port[][3])
{
    for(int i=0; i<=2; i++)
        pinMode(port[0][i],OUTPUT);
    pinMode(port[1][0],INPUT);
    for(int i=1; i <= 2; i++){
        pinMode(port[RECEIVE][i],INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(port[RECEIVE][i]), stateAlternate, CHANGE);
    }
}

void
ulterSend(int Trig)
{
    int time;

    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);

    time = micros();
    for(int i=0; i <= 2; i++ )
          stateTime[SEND][Trig] = time;
}

void
stateAlternate(int echo)
{
    stateTime[SEND][echo] = micros();
    ulterSend(echo);
}
