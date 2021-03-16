#include "SonarModule.h"

#define trigPin 12
#define echoPin 13

SonarModule sonar(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
}

void loop() {

  float distance = sonar.ping_distance(); 
  Serial.println(distance);
  delay(1000);
}
