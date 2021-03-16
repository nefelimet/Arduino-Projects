#include "thermistor.h"

//The thermistor's nominal value (resistance at 25 degrees Celsius) in Kohms.
#define Rref 100

//The external resistance in order to create voltage divider in kOhms. Use a resistance that is not negligible compared to thermistor's nominal value.
#define R 4.7

//The thermistor's constants for the Steinhart and Hart equation, taken from the datasheet.
#define A 3.354016 * pow(10, -3)
#define B 2.460382 * pow(10, -4)
#define C 3.405377 * pow(10, -6)
#define D 1.034240 * pow(10, -7)

#define thermPin A0

Thermistor therm(A, B, C, D, Rref, R, thermPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  therm.printData();
  delay(1000);
}
