#ifndef THERMISTOR_H
#define THERMISTOR_H

#include "Arduino.h"

//Connections: resistance R and thermistor connected in series as a voltage divider. Thermistor's voltage taken as input into analog pin "pin"

class Thermistor{
public:
  Thermistor(double A, double B, double C, double D, float Rref, float R, byte pin);
  int takeMeasurement();
  float measureResistance();
  float findTemperature();
  void printData();
  float simpleFilter(int times);

private:
  //Variables A, B, C, D are the thermistor's constants according to the datasheet.
  double A;
  double B;
  double C;
  double D;

  //Reference resistance in Kohms, that is the thermistor's nominal resistance, found in the datasheet
  float Rref;

  //Resistance R in Kohms connected in series to thermistor
  float R;

  //Analog input pin
  byte pin;
};

#endif
