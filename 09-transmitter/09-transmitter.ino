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

  delay(3000);
  myFrame.id=0x08;
  myFrame.length=2;
  uint16_t rnum = random(65535);
  memcpy(myFrame.data.bytes, &rnum, sizeof(rnum));
  Can0.sendFrame(myFrame);
}
