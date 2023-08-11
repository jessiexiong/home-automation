// include the library code:
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int VRX_PIN = A0; // Arduino pin connected to VRX pin
const int VRY_PIN = A1; // Arduino pin connected to VRY pin

const int SW_PIN = 8;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;


int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int bValue = 0; // store button state

// Define an enum type named "Color"
enum Color {
    HELLO_WORLD,    // 0
    RED_PAGE = -1,  // -1
    GREEN_PAGE = -2,    // -2
    BLUE_PAGE = -3,   //-3
    TURN_OFF_PAGE=-4  //-4
};


byte downArrow[8] = {
	0x0,0x0,0x0,0x1f,0xe,0x4,0x0,0x0
};

int pageState=0;

void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);  
  pinMode(VRX_PIN, INPUT);  
  pinMode(VRY_PIN, INPUT);  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.createChar(1, downArrow);

  lcd.setCursor(0, 0);
  lcd.print("hello world");
  // lcd.setCursor(0, 1);
  // lcd.write(1);
}


bool redOn = false;
bool greenOn = false;
bool blueOn = false;

void loop() {
    // setColor(196, 44, 29); // Red Color
    // delay(1000);
    // setColor(80, 125, 10); // Green Color
    // delay(1000);
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  bValue = digitalRead(SW_PIN);   
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);

  if(yValue < 300){
    pageState++;
  }
  else if (yValue > 900){
    pageState--;
  }


// handle different pageStates
  switch(pageState) {
    case HELLO_WORLD:
      updateDisplay("Hello world");
      lcd.setCursor(0, 1);
      lcd.write(1);
      break;
    case RED_PAGE:
      updateDisplay("PAIN");
      break;
    case GREEN_PAGE:
      updateDisplay("green");
      break;
    case BLUE_PAGE:
      updateDisplay("blue");
      break;
    case TURN_OFF_PAGE:
      updateDisplay("turnoff");
      break;
    default:
      if (pageState > 0 ){
        pageState = 0;
      }
      if (pageState <-4){
        pageState = -4;
      }
  }

  if (bValue<1){
    switch (pageState){
      case RED_PAGE:
        if (redOn) {
            setColor(0, 0, 0);  // Turn off LED
        }
        else {
            setColor(255, 0, 0);  // Set LED color to red
        }
        redOn = !redOn;  // Toggle the boolean variable
        break;
      case GREEN_PAGE:
        if (greenOn) {
            setColor(0, 0, 0);  // Turn off LED
        }
        else {
            setColor(0, 255, 0);  // Set LED color to red
        }
        greenOn = !greenOn;
        break;
      case BLUE_PAGE:
        if (blueOn){
          setColor(0,0,0);          
        }
        else{
          setColor(0,0,255);
        }
        blueOn = !blueOn;
        break;
      // default:
      //   if (lightOn){
      //     lightOn = false;
      //     setColor(0,0,0);
      //   }
    }
  }
  delay(180);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void updateDisplay(String message){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
    lcd.setCursor(0, 1);
    lcd.print(pageState);
}

