#include "due_can.h"

static CAN_FRAME rxBuff;

const int LED_PIN = 2;

void setup() {
  Serial.begin(9600);
  Can0.begin();
}

void loop() {
  if (Can0.rx_avail())
  {
    Can0.read(rxBuff);
    if (rxBuff.id == 0x07) {
      outputToLED(); // TODO: fix this
    }
  }
}

void outputToLED(uint8_t brightness) {
  analogWrite(LED_PIN); // TODO: fix this
}
