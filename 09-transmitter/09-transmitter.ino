#include "due_can.h"

void setup() {
  Can0.begin();
}

void loop() {
  delay(3000);
  CAN_FRAME myFrame;
  myFrame.id=0x07;
  myFrame.length=1;
  myFrame.data.bytes[0]=random(255);
  Can0.sendFrame(myFrame);
}
