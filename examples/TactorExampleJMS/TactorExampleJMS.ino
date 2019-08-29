/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//distance sensor sees
int distance;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  if (distance < 200 && distance>15) {
    digitalWrite(2, HIGH);   // turn the port on (HIGH is the voltage level)
  } else {                  // wait for a second
    digitalWrite(2, LOW);    // turn the port off by making the voltage LOW
    delay(500);
  }
  
}
