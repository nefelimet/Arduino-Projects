//This example doesn't use the library, but has all the function here.

//The thermistor's nominal value (resistance at 25 degrees Celsius) in Kohms.
#define Rref 100

//The external resistance in order to create voltage divider in kOhms. Use a resistance that is not negligible compared to thermistor's nominal value.
#define R 4.7

//The thermistor's constants for the Steinhart and Hart equation, taken from the datasheet.
#define A 3.354016 * pow(10, -3)
#define B 2.460382 * pow(10, -4)
#define C 3.405377 * pow(10, -6)
#define D 1.034240 * pow(10, -7)

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int measurement = analogRead(A0);
  int a = 1023 - measurement;
  float b = measurement / a;
  
  //Thermistor resistance in kOhms
  float resistance = b * R;

  //Previous method: used to overflow because of huge numbers. Leaving this for educational reasons.
  //float resistance = measurement * R / (1023 - measurement);
  //float temperature = 1 / (A + B*log(resistance/100000) + C*pow(log(resistance/100000),2) + D*pow(log(resistance/100000),3));

  //Temperature is found using the Steinhart and Hart equation.
  float temperature = 1 / (A + B*log(resistance/Rref) + C*pow(log(resistance/Rref),2) + D*pow(log(resistance/Rref),3));
  
  Serial.print("Raw: ");
  Serial.print(measurement);
  Serial.print("     ");  
  Serial.print("Rth: ");
  Serial.print(resistance);
  Serial.print(" kOhms     ");
  Serial.print("T: ");
  Serial.print(temperature);
  Serial.print(" K");
  Serial.print(" ");
  Serial.print("or ");
  Serial.print(temperature - 273);
  Serial.println(" C.");
  
  delay(1000);
}
