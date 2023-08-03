// // Define the pin number for the LED
// const int motorPin = 3;

// // Define the pin number for the pushbutton
// const int buttonPin = 2;

// // Variable to store the previous state of the button
// int previousButtonState = LOW;

// // Variable to store the current state of the LED
// int motorState = LOW;
// int speed = 100;
// void setup() {
//   // Initialize the LED pin as an output
//   pinMode(motorPin, OUTPUT);
//   // Initialize the pushbutton pin as an input with internal pull-up resistor enabled
//   pinMode(buttonPin, INPUT);
// }

// void loop() {
//   // Read the current state of the pushbutton
//   int buttonState = digitalRead(buttonPin);

//   // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//   if (buttonState == HIGH) {
//     // turn LED on:
//     digitalWrite(motorPin, HIGH);
//   } else {
//     // turn LED off:
//     digitalWrite(motorPin, LOW);
//   }
//   // // Check if the button state has changed from the previous state
//   // if (currentButtonState != previousButtonState) {
//   //   // If the button is pressed (transition from HIGH to LOW)
//   //   if (currentButtonState == LOW) {
//   //     // Toggle the LED state
//   //     motorState = !motorState;
//   //     // Update the LED with the new state
//   //     analogWrite(motorPin, speed);
//   //   }
//   //   // Update the previousButtonState with the current state for the next iteration
//   //   previousButtonState = currentButtonState;
//   // }
// }


int ButtonValue = 0;


const int Button = 3;
const int LED = 2;
const int motorPin = 5;
int speed = 50;
void setup(){
  Serial.begin(9600);
     pinMode(Button, INPUT_PULLUP);
     pinMode(LED, OUTPUT);
     pinMode(motorPin, OUTPUT);
}


void loop(){    
    ButtonValue = digitalRead(Button);
    Serial.println(ButtonValue);

    if(ButtonValue != 1){
      digitalWrite(LED, HIGH);
      analogWrite(motorPin, 100);
    }
    else
    {
      digitalWrite(LED, LOW);
      analogWrite(motorPin, 0);
    }
}

// int motorPin = 3;
 
// void setup() 
// { 
//   pinMode(motorPin, OUTPUT);
//   Serial.begin(9600);
//   while (! Serial);
//   Serial.println("Speed 0 to 255");
// } 
 
// int speed = 0;
 
// void loop() 
// { 

//       analogWrite(motorPin, speed);
// } 