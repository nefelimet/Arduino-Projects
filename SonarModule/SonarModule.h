#ifndef SONARMODULE_H
#define SONARMODULE_H

#include "Arduino.h"

class SonarModule{
public:
  SonarModule(int trigPin, int echoPin);
  unsigned long ping();
  float ping_distance();
  void sendPulse(int pin, unsigned long time_us);
  unsigned long readPulse(int pin);
private:
  int trigPin;
  int echoPin;
};

#endif
