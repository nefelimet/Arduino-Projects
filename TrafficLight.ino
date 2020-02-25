//This uses a RGB Common Cathode LED, and an HC_SR04 ultrasonic sensor
//The LED lights up in different colours, according to the distance of an object from the sensor

#include <NewPing.h>
NewPing sonar(12, 13, 200);

void setup(){
  Serial.begin(9600);
  pinMode(11, OUTPUT);      //red
  pinMode(10, OUTPUT);      //green
  pinMode(9, OUTPUT);       //blue
}

void loop(){
  int distance = sonar.ping_cm();
  Serial.println(distance);

  //if distance is up to 5 cm, the LED becomes red
  if(distance <=5 && distance >0){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }

  //if distance is between 5 and 10 cm, the LED becomes blue
  else if (distance > 5 && distance <= 10){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }

  //if distance if bigger than 10 cm, the LED becomes green
  else if (distance >10){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  else{
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  delay(1000);
}
