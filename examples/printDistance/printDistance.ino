/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
   left uncommented so students can explain it
*/

#include <DistanceSensor.h>

DistanceSensor distancesensor;
double distance;

void setup() {
  
  distancesensor.begin(10, 11);
  
  Serial.begin(9600);

}

void loop() {
  
  distance=distancesensor.getDistance();
  
  Serial.println(distance);
  
  delay(500);
}
