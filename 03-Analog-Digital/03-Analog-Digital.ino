#include "due_can.h"

static CAN_FRAME rxBuff;

const int LED_PIN = 2;

void setup() {
  Serial.begin(9600);
  Can0.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (Can0.rx_avail())
  {
    Can0.read(rxBuff);
    if (rxBuff.id == 0x07) {
      outputToLED(); // TODO: fix this function call
      delay(1000);
    }
  }
}

void outputToLED(uint8_t brightness) {
  //TODO: implement this
}

/**
 * 3
 * 
 * In this tutorial, you will perform analog and digital input/output
 * operations. You'll combine this with the CAN bus to design a
 * system similar to our motor controller system. Performing I/O
 * based on CAN messages is also done in our power distribution
 * system.
 * 
 * Exercise 1: As you saw in the last tutorial, a random number
 * is being generated and sent on CAN ID 0x07. Your challenge is to
 * set the brightness of an LED based on this number. Here are the
 * things you need to do:
 *  Step 1: Implement outputToLED(uint8_t brightness). Hint: 
 *  look up the analogWrite() function.
 *  Step 2: In the loop() function, fix the call to outputToLED()
 *  (give it a parameter).
 * After wiring up an LED on analog pin 2, this code should cause the
 * brightness to change every second. (Refer to the Due pinout diagram
 * for help wiring the LED: 
 * https://content.arduino.cc/assets/Pinout-Due_latest.pdf)
 * 
 * Exercise 2: Now, add a feature where a button wired to the Arduino
 * can be used to turn off the LED while it's pressed. When the button 
 * is released, the LED should turn back on and its brightness should
 * depend on the CAN message just as before. Hint: For some help wiring 
 * the button, refer to the pinout diagram linked above. For the coding
 * part, look up the digitalRead() function. Make sure to set the 
 * pin mode in setup() as well (look up pinMode()). If you aren't
 * using an external pullup or pulldown resistor, use the mode
 * INPUT_PULLUP. Extra credit if you learn what a pullup or pulldown
 * resistor does.
 */
