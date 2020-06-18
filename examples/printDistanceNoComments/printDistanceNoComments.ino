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
