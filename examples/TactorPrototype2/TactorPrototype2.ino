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
  if(distance<200){
    //encode distance for calibration
    pulseXTimes(distance/10);
    delay(2000);
}
}
void pulseXTimes(int numTimes){
  for(int i=0;i<numTimes;i++){
      pulse(200);
  }
}

void pulse(int pulseTime){
 digitalWrite(2, HIGH);
  delay(pulseTime);
  digitalWrite(2, LOW);
  delay(pulseTime);      
}
