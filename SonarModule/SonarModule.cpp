#include "SonarModule.h"

SonarModule::SonarModule(int trigPin, int echoPin){
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/*Params: none
  Returns: ping time in microseconds
*/
unsigned long SonarModule::ping(){
  //Send a pulse signal through trig pin for 10 microseconds
  sendPulse(trigPin, 10);

  //After the pulse on trigPin has fired, the module sends an eight cycle sonic burst at 40kHz.
  //After the sonic burst has been sent, the echoPin will immediately go HIGH, and remain so until the reflecting wave hits back.
  //We don't know the duration of the sonic burst, so we wait until echoPin reads HIGH.

  while(digitalRead(echoPin) == LOW){
    delayMicroseconds(1);
  }

  //Receive the signal back through echo pin
  unsigned long read_time = readPulse(echoPin);

  //Return the time difference in microseconds
  return read_time;
}

/*Params: none
  Returns: distance of the object in cm
*/
float SonarModule::ping_distance(){
  //Ping time in microseconds
  unsigned long read_time = ping();

  //Measure distance in cm
  //velocity of sound = 343 m/s = 343 * 100cm / 10^6 us = 343 * 10^-4 cm/us
  float velocity = 343 * pow(10, -4);

  //distance = v * t / 2, because the time is measured round-trip
  float distance = read_time * velocity / 2;
  return distance;
}

/*Params: pin - the pin to which we want to send the pulse
          time_ms - the time of the pulse in microseconds
  Returns: none
*/
void SonarModule::sendPulse(int pin, unsigned long time_us){
  //
  unsigned long timer_1 = micros();
  //As long as the time that has passed since this function was called is less than the time we want for the pulse to be HIGH, keep writing HIGH
  while(micros() - timer_1 <= time_us){
    digitalWrite(pin, HIGH);
  }
  digitalWrite(pin, LOW);
}

/*Params: pin - the pin from which we read the readPulse
Returns: pulse duration in microseconds
*/
unsigned long SonarModule::readPulse(int pin){
  //We assume that when this function is called, the pin has just gone to HIGH state.
  unsigned long timer_1 = micros();
  unsigned long read_time;

  //As long as the pin is HIGH, the time interval is the difference between current time and timer_1
  while(digitalRead(pin) == HIGH){
    read_time = micros() - timer_1;
  }

  //We return the last time interval measured
  return read_time;
}
