/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//distance sensor sees
double distance;
//the port of the vibrator
int vibPin=2;
//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(vibPin, OUTPUT);

}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //vibrates if distance is within range
  if (distance < 80 && distance>5) {
    digitalWrite(vibPin, HIGH);   
  //otherwise turns fibrator off and waits x milliseconds
  } else {                  
    digitalWrite(vibPin, LOW);    
  }
  delay(500);
}
