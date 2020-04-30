/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//include the backgound library needed to run the distance sensor
#include <DistanceSensor.h>
//name the distane sensor
DistanceSensor distancesensor;
//variable to store the distance
double distance;
//runs once
void setup() {
  //start the distance sensor
  distancesensor.begin(5, 6);
  //start the usb connection to the computer
  Serial.begin(9600);

}
//runs many times
void loop() {
  //get the distance
  distance=distancesensor.getDistance();
  //print the distance to the serial monitor
  Serial.println(distance);
  //wait for a number of milliseconds
  delay(500);
}
