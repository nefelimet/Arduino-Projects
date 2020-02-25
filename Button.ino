//This uses a simple button and a LED
//When the button is pressed, the LED lights up. When we stop pressing the button, the LED turns off.

void setup() {
  pinMode(4, INPUT);        //input from the button
  pinMode(8, OUTPUT);       //output for the LED
}

int lastButtonState = digitalRead(4);

void loop() {
  if (lastButtonState == HIGH){
    if (digitalRead(4) == HIGH) digitalWrite(8, LOW);
    else digitalWrite(8,HIGH);
  }
  else if (lastButtonState == LOW){
    if (digitalRead(4) == HIGH) digitalWrite(8,HIGH);
    else digitalWrite(8,LOW);
  }

  lastButtonState = digitalRead(4);
}
