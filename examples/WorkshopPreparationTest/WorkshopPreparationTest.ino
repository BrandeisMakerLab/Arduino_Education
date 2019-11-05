/* Prints distance and blinks LED so I can prepare workshop kits
 *  Jcob Smith 11/1/2019 Braneis Univeristy Automation Laborotory
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor

int distance;


//runs once
void setup() {
  pinMode(2, OUTPUT);
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);

}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  if (distance<50 && distance >6){
     digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW 
  }
  delay(500);            
}
