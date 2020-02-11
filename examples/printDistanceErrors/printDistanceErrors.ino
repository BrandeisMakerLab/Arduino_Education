/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
   This version deliberately has errors to practice common mistakes
*/

//name the distane sensor
DistanceSensor distancesensor;
//variable to store the distance
double distance;
//runs once
void setup() {
  //start the distance sensor
  distancesensor.begin(10, 11);
  //start the usb connection to the computer
  Serial.begin(9600)

}
//runs many times
void loop() {
  //get the distance
  distance=distancesenser.getDistance();
  //print the distance to the serial monitor
  Serial.println(distanc)
  //wait for a number of milliseconds
  delay(500);
}
