// include the library code:
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int VRX_PIN = A0; // Arduino pin connected to VRX pin
const int VRY_PIN = A1; // Arduino pin connected to VRY pin
const int SW_PIN = 8;


int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int bValue = 0; // store button state

byte downArrow[8] = {
	0x0,0x0,0x0,0x1f,0xe,0x4,0x0,0x0
};

void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);  
  pinMode(VRX_PIN, INPUT);  
  pinMode(VRY_PIN, INPUT);  
  
  lcd.begin(16, 2);
  lcd.createChar(1, downArrow);

  lcd.setCursor(0, 0);
  lcd.print("hello world");
  lcd.setCursor(0, 1);
  lcd.write(1);
}

void updateDisplay(String message){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}

void loop() {
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  bValue = digitalRead(SW_PIN);   
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);

  if(yValue > 900){
    updateDisplay("hiya");
  }
  else if (yValue < 300){
    updateDisplay("bye a");
  }

  if (bValue<1){
    updateDisplay("GOD HELP");
  }

  delay(500);
}
