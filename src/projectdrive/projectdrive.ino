#include "motor-ctl.h"
void setup() {
    portsetup();
}

void loop() {
  forward(1000);
  backward(1000);
  toleft(1000);
  toright(1000);
  takebreak(1000);

}
