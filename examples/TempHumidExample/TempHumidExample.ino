//imports the library that must be used to run this program
#include <DHT.h>
#include <DHT_U.h>

//initializes the part so that the program knows what to expect to run
DHT dht(2,DHT22);

void setup() {
  //initialize serial port (allows for commuication with arduino by clicking on the magnifying glass
  //on the top right corner of the window AFTER the program is uploaded
  Serial.begin(9600);
  //starts the loop
  dht.begin();
}
void loop() {
  
  float humidity = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(500);
}
