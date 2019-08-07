/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor

int distance;
int led = 3;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(11, INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  if (distance < 200 && distance>0) {
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
  } else {                  // wait for a second
    digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
    delay(500);

  }
  analogWrite(3, (distance - 40) * 5);
}
