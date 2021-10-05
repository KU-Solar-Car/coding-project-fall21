#include "due_can.h"

static CAN_FRAME rxBuff;

void setup() {
  Serial.begin(9600);
  Can0.begin();
  Can0.watchFor();
}

void loop() {
  if (Can0.rx_avail())
  {
    Can0.read(rxBuff);
    onCanRx(&rxBuff);
  }
}

void onCanRx(CAN_FRAME* frame) {
  Serial.print("Got CAN Frame. ID: ");
  Serial.print(frame->id, HEX);
  Serial.print(", Length: ");
  Serial.print(frame->length, HEX);
  Serial.print(", Data: ");
  for (int i = 0; i < frame->length; i++)
  {
    Serial.print(frame->data.bytes[i]);
    Serial.print(" ");
  }
  Serial.println();

  // ====================================
  // Your part
  if (frame->id == 0x07)
  {
    // Do something with the frame if the id is 0x07
  }

  // Do something with the frame if the id is 0x08
}

/*
 * 2
 * 
 * Connect the Green CAN wire to CAN_H (high) and the White CAN wire to CAN_L (low) on the Arduino.
 * Use CAN0. Upload this program to the Arduino and watch what happens.
 * 
 * Exercise 1: A numeric value is being transmitted on CAN ID 0x07. The code is already
 * written to print this number as hex to the serial monitor. Now, write code that will
 * print this number as decimal in the block that says if (frame->id == 0x07)...
 *
 * Hint: The data of a CAN message is stored in frame->data.bytes[i]. The type of this
 * is uint8_t (unsigned 8-bit integer), which is already a numeric data type, so you don't
 * need to convert.
 *
 * Exercise 2: Another numeric value is being transmitted on CAN ID 0x08. In a new if block
 * below the one you just wrote, print this value to the Serial monitor.
 *
 * Hint: This is a little bit trickier because the value is now two bytes long. You will
 * need to use bit shifting in order to put these two bytes in a uint16_t (16-bit unsigned
 * integer).
 */
