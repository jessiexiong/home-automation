#include <Arduino.h>

const int latchPin = 10;  // ST_CP pin
const int clockPin = 11;  // SH_CP pin
const int dataPin = 12;   // DS pin

// Define the digital map for individual LEDs
const byte ledMap[] = {
  B0001, // LED 0
  B0010, // LED 1
  B0100, // LED 2
  B1000,  // LED 3
  B10000  // LED 3
};

void setup() {
  // Setup pins as Outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void displayLEDs(byte pattern) {
  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);

  // Shift out the bits for the LED pattern
  shiftOut(dataPin, clockPin, MSBFIRST, pattern);

  // ST_CP HIGH to change LEDs and update the display
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // Light up LEDs 0 and 2 together
  displayLEDs(ledMap[0] | ledMap[2]);
  delay(1000); // Display both LEDs for 1 second

  // Light up LEDs 1 and 3 together
  displayLEDs(ledMap[1] | ledMap[3]);
  delay(1000); // Display both LEDs for 1 second

    // Light up LEDs 1 and 3 together
  displayLEDs(ledMap[2] | ledMap[4]);
  delay(1000); // Display both LEDs for 1 second

  // Turn OFF all LEDs
  displayLEDs(0);
  delay(1000); // Turn OFF all LEDs for 1 second
}
