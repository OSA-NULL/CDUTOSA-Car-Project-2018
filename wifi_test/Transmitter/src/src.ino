/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 rf24(7, 8); // CE, CSN

const byte addr[] = "1Node";
const char msg[] = "The number is ";
int digit=0;

void setup() {
  rf24.begin();
  rf24.setChannel(83);
  rf24.openWritingPipe(addr);
  rf24.setPALevel(RF24_PA_MIN);
  rf24.setDataRate(RF24_250KBPS);
  rf24.stopListening();
}
void loop() {
  rf24.write(&msg, sizeof(msg));
  rf24.write(&digit, sizeof(int));
  delay(1000);
  digit++;
}
