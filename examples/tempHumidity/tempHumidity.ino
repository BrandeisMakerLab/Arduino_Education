/* Written by Jacob Smith for Brandeis Automation Laboratory 11/7/20
 *  Demonstrates the use of teh DHT Humidt and temperature sensor
 *  Note: requires DHT background library, which can be installed automatically
 * Wiring: S-->Digital 3, Power-->3.3V, - --> GND
*/

//dht type, resistor, timing
//imports the library that must be used to run this program
#include <DHT.h>

//sets up the sensor, plugged into digital port 3
DHT dht(3,DHT11);

//runs once
void setup() {
  //initialize serial port (allows for commuication with arduino by clicking on the magnifying glass
  //on the top right corner of the window AFTER the program is uploaded
  Serial.begin(9600);
  //starts the loop
  dht.begin();
  Serial.println("Humidity\tTemperature");
}

//runs many times
void loop() {

  //read the humidity
  float humidity = dht.readHumidity();

   // Read temperature as Fahrenheit (isFahrenheit = true)
  float temp = dht.readTemperature(true);

  //display data
  Serial.print(humidity);
  Serial.print("\t");
  Serial.println(temp);
  //wait x milliseconds so printout it slower
  delay(1000);
}
