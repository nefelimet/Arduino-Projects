//Simple button and led application. Clicking the button will change the LED's state for as long as the button stays clicked.
//We are using pullup resistor on the input pin, so its logic is inverted.

//Connections: button's 1st pin -> buttonPin
//             button's 2nd pin -> GND
//             led's anode      -> ledPin
//             led's cathode    -> GND through 2.2kOhm resistance

#define ledPin 8
#define buttonPin 4
#define defaultLedStateOn false

int buttonRead;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonRead = digitalRead(buttonPin);
  
  if(defaultLedStateOn){
    if (buttonRead == HIGH) digitalWrite(ledPin, HIGH);
    else digitalWrite(ledPin, LOW);
  }
  else{
    if (buttonRead == HIGH) digitalWrite(ledPin, LOW);
    else digitalWrite(ledPin, HIGH);
  }  
}
