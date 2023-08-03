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