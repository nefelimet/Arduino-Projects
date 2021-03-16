#include "thermistor.h"

Thermistor::Thermistor(double A, double B, double C, double D, float Rref, float R, byte pin){
  this->A = A;
  this->B = B;
  this->C = C;
  this->D = D;
  this->Rref = Rref;
  this->R = R;
  this->pin = pin;
}

int Thermistor::takeMeasurement(){
  return analogRead(this->pin);
}

float Thermistor::measureResistance(){
  int measurement = takeMeasurement();
  int a = 1023 - measurement;
  float b = measurement / a;
  float resistance = b * R;
  return resistance;
}

float Thermistor::findTemperature(){
  float resistance = measureResistance();
  
  //Temperature is found using the Steinhart and Hart equation.
  float temperature = 1 / (A + B*log(resistance/Rref) + C*pow(log(resistance/Rref),2) + D*pow(log(resistance/Rref),3));
  return temperature;
}

void Thermistor::printData(){
  Serial.print("Raw: ");
  Serial.print(takeMeasurement());
  Serial.print("     ");
  Serial.print("Rth: ");
  Serial.print(measureResistance());
  Serial.print(" kOhms     ");
  Serial.print("T: ");
  Serial.print(findTemperature() - 273);
  Serial.println(" C.");
}

float Thermistor::simpleFilter(int times){
  float sum = 0;
  for (int i=0; i<times; i++){
    sum += findTemperature();
  }
  return sum / times;
}
