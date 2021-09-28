void setup() {

}

void loop() {

}

/* 
 * 1
 *
 * This is the most basic Arduino program possible: an empty setup() and an
 * empty loop(). Plug in an Arduino Due to your computer (use the microUSB port on the right). 
 * In the top bar, select Tools > Board > Arduino SAM Boards > Arduino Due (Programming Port).
 * Now, click the Upload button in the IDE. A terminal window should pop up showing you the
 * upload progress. When it's done, open the serial monitor and you'll see that nothing is happening.
 *
 * Exercise: Add the following lines inside the body of setup():
 *
 *   Serial.begin(9600);
 *   Serial.println("Hello, World!");
 *
 * So the full program should look like this:
 * ===================================
 * void setup() {
 *   Serial.begin(9600); // This line has two spaces before it
 *   Serial.println("Hello, World!");
 * }
 * 
 * void loop() {
 * 
 * }
 * ===================================
 * Upload the program to the Arduino, open the serial monitor, and watch what happens.
 * 
 * Next up: Navigate to 02-CAN/02-CAN.ino
 */
