#include "due_can.h"

void setup() {
  Serial.begin(9600);
  Can0.begin();
  Can0.setGeneralCallback(onCanRx);
}

void loop() {
  
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
  if (frame->id == 0x00)
  {
    Serial.print("The secret number is: ");
    Serial.println(); // What goes in the parenthesis?
  }
}

/*
 * 2
 * 
 * Connect the Green CAN wire to CAN_H (high) and the White CAN wire to CAN_L (low) on the Arduino.
 * Use CAN0. Upload this program to the Arduino and watch what happens.
 * 
 * Exercise 1: There is some code written to tell the user nicely that there is a secret number, but it
 * doesn't seem to be running at all. See if you can find the problem and fix it. Your resources are
 * the code that prints all CAN frames and/or the due_can tutorial: https://github.com/collin80/due_can/blob/master/howtouse.txt
 * 
 * Exercise 2: The Arduino at the other end of the CAN Bus is sending a secret number. Get that secret number
 * from the CAN frame and print it in the line that says "What goes in the parenthesis?"
 * 
 * Exercise 3: Notice that there are two different lengths of messages being sent, 1 and 2.
 * The length field represents the number of bytes in the message. Therefore, one of the
 * messages is 1 byte long (8 bits), and the other is 2 bytes long (16 bits).
 * Each message is intended to represent a single number.
 * Your goal, then, is to extract the 1-byte-long message into a variable of the type 
 * uint8_t, and the 2-byte-long message into a variable of the type uint16_t, and then
 * print both to the serial monitor. Hint: The 2-byte-long message will require you to
 * use the bit shift (<<) operator.
 * 
 * Extra Credit: What do you think the line Can0.setGeneralCallback(onCanRx) does?
 */
