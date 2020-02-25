//This uses a DHT11 temperature and humidity sensor, to measure and print out temperature and relative humidity of the environment the circuit is in

#include <dht.h>
dht DHT;
#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;                      //if everything is ok
    case -1: Serial.println("Checksum error"); break;         //if there's a checksum error
    case -2: Serial.println("Time out error"); break;         //if there's a timeout error
    default: Serial.println("Unknown error"); break;          //if there's an unknown error
  }
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(5000);
}
