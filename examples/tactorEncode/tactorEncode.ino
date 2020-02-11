/* Encodes the distance in tactor pulses
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//the distance to the sensor
double distance;
int vibPin = 2;

//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  //set vibrator pin to output
  pinMode(vibPin, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //if the distance is within range, invoke helper method
  if (distance < 200) {
    //encode distance for calibration
    pulseXTimes(distance / 10);
    //wait x seconds
    delay(2000);
  }
}
//pulses the provided number of times
void pulseXTimes(int numTimes) {
  //loops throhg number of times
  for (int i = 0; i < numTimes; i++) {
    pulse(200);
  }
}
//pulses for the specified period of time
void pulse(int pulseTime) {
  digitalWrite(vibPin, HIGH);
  delay(pulseTime);
  digitalWrite(vibPin, LOW);
  delay(pulseTime);
}
