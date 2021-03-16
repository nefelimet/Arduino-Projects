//Simple button and led application. Clicking the button will change the LED's state for as long as the button stays clicked.

//Connections: button's 1st pin -> +5V
//             button's 2nd pin -> GND through 10kOhm resistance, and also to buttonPin
//             led's anode      -> ledPin
//             led's cathode    -> GND through 2.2kOhm resistance

#define ledPin 8
#define buttonPin 4
#define defaultLedStateOn true

int buttonRead;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonRead = digitalRead(buttonPin);

  if(defaultLedStateOn){
    if (buttonRead == HIGH) digitalWrite(ledPin, LOW);
    else digitalWrite(ledPin, HIGH);
  }
  else{
    if (buttonRead == HIGH) digitalWrite(ledPin, HIGH);
    else digitalWrite(ledPin, LOW);
  }
}
