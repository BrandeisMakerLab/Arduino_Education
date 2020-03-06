/* vibrates tactor for x milliseconds base don how far away object is
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;
//distance sensor sees
int distance;
int vibPin=2;
int buzzerPin=3;
//the port of the vibrator
//runs once
void setup() {
  //sets up the class
  distancesensor.begin(10, 11);
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  //set vibrator to output
  pinMode(vibPin, OUTPUT);

}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //if distance is withing range, pulse depending on range
  if (distance < 80 && distance>5) {
    // turn the port on
    tone(buzzerPin,distance*-5+700);
    digitalWrite(vibPin, HIGH);   
    //wait for x milliseconds
    delay(distance*10);
    digitalWrite(vibPin, LOW);
    noTone(buzzerPin);
    delay(distance*10); 
  }  
}
