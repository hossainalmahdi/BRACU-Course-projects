#include "DHT.h"
#define DHTPIN 2 //digital pin connected to the DHT sensor
#define DHTTYPE DHT11 //DHT 11
DHT dht(DHTPIN,DHTTYPE);
void setup(){
  Serial.begin(9600);
  Serial.println("Group11_Lab1_Section01");
  dht.begin();
}
void loop(){
  //Wait a few moment between measurements
  delay(1000);
  //Reading temperature or humidity takes about 250 milliseconds
  //Sensor readings may also be up to 2 seconds 'old'(its very slow sensor)
  float h=dht.readHumidity();
  //Read temperature as Celsius(the default)
  float t=dht.readTemperature();
  //Read temperature as Farenheit(isFarenheit=true)
  float f=dht.readTemperature(true);

  //Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read the DHT sensor!"));
    return;
  }
  //Compute heat index in Farenheit (the default)
  float hif = dht.computeHeatIndex(f,h);
  //Compute heat index in Celsius(isFarenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  //Serial.print("Temp: ");
  Serial.println(t);
  //Serial.print("Humidity: ");
  Serial.println(h);
}
