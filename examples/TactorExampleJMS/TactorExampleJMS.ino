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

  pinMode(led, OUTPUT);
  pinMode(11, INPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(2, OUTPUT);

}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);

  if ( !outBounds(distance)) {//lesss than 15 could be junk
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {                  // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  
  }
     delay(200);

  if (distance < 200 && distance>15) {
    digitalWrite(2, HIGH);   // turn the port on (HIGH is the voltage level)
  } else {                  // wait for a second
    digitalWrite(2, LOW);    // turn the port off by making the voltage LOW
    delay(500);
  }
  

}

boolean outBounds(int distance){
  return (distance>50 && distance<70)||distance>200;
  }
