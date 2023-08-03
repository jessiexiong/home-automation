#include "SevSeg.h"
#include <stdio.h>
#include <string.h>
SevSeg sevseg; //Initiate a seven segment controller object
int result = 0;
unsigned long lastUpdateTime = 0; // Variable to store the last update time

void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    bool resistorsOnSegments = 0; 
    // variable above indicates that 4 resistors were placed on the digit pins.
    // set variable to 1 if you want to use 8 resistors on the segment pins.
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(70);
    Serial.begin(9600);
    getTime();
    sevseg.setNumber(result, 2);
}

void loop() {
    unsigned long int current_time = millis();
    if (current_time - lastUpdateTime >= 1000){
      // getTime();
      result++;
      sevseg.setNumber(result, 2);
      lastUpdateTime = current_time;
    }
    sevseg.refreshDisplay(); // Must run repeatedly


}

void getTime(){
    char ct[] = __TIME__;
    for(int i = 0; i<5; i++){
      Serial.println(ct[i]);
    }
    
    char ct2[4] = {0};
    for (int i = 0; i<5; i++){
      if (i<2){
        ct2[i] = ct[i];
      }
      else if (i>2){
        ct2[i-1] = ct[i];
      }
    }
    result = atoi(ct2);
    Serial.println(result);
}