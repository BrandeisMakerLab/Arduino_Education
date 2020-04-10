/*
 * Temperature Pressure Altitude Sensor Demo for 16 sensor kit
 * Curated by Jacob Smith for Brandeis Automation Laboratory
 * From: https://simple-circuit.com/arduino-bmp280-sensor-lcd/
 */
//include background library for sensor
#include <Adafruit_BME280.h>  // include adafruit library for BME280 sensor
//the library object 
Adafruit_BME280 bme280;

//runs once for setup
void setup()
{
  ///start usb connection to Arduino
  Serial.begin(9600);
  //wait for connectino to start
  while(!Serial){} 
  //print demonstration prompt
  Serial.println("Temperature Humidity Pressure Sensor Demonstration");
  //start the snesor at specified address
  if (!bme280.begin(0x76))
  {  
    //if the sensor doesn't connect, print warning
    Serial.println("Could not find a valid BME280 sensor, check wiring and reupload");
    //wait forever so user uploads
    while (1);
  }
 
}

//runs many times
void loop()
{
  // print temperature
  Serial.print("\nTemperature    (°C) = ");
  //read temperature
  Serial.print(bme280.readTemperature());
  // print and read humidity
  Serial.print("\nHumidity        (%) = ");
  Serial.print(bme280.readHumidity());
  // print and read pressure
  Serial.print("\nPressure      (hPa) = ");
  Serial.print(bme280.readPressure()/ 100);
  // print and read altidue
  Serial.print("\nApprox Altitude (m) = ");
  Serial.println(bme280.readAltitude(1013.25));
  //wait x milliseconds for printing
  delay(2000); 
  
}
