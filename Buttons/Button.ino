//Button and led application. When we click the button, the led lights up and stays this way until we click the button again.

//Connections: button's 1st pin -> +5V
//             button's 2nd pin -> GND through 10kOhm resistance, and also to buttonPin
//             led's anode      -> ledPin
//             led's cathode    -> GND through 2.2kOhm resistance

#define ledPin 8
#define buttonPin 4

int buttonRead;
int lastLedState = LOW;
bool buttonPressed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonRead = digitalRead(buttonPin);
  
  //If the button was unclicked previously and we've just clicked it now
  if(buttonRead == HIGH && buttonPressed == false){
    buttonPressed = true;
    digitalWrite(ledPin, !lastLedState);
    lastLedState = !lastLedState;
  }
  //If the button was already clicked previously and it is still being clicked
  else if (buttonRead == HIGH && buttonPressed == true){
    buttonPressed = true;
    digitalWrite(ledPin, lastLedState);
  }
  //If the button is not being clicked
  else{
    buttonPressed = false;
    digitalWrite(ledPin, lastLedState);  
  }
}
