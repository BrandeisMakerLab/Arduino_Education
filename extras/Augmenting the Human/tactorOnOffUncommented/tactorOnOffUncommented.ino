/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
   Left uncommented so students can explain the program themselves
*/

#include <DistanceSensor.h>

DistanceSensor distancesensor;

double distance;

int vibPin=2;

void setup() {
 
  distancesensor.begin(10, 11);
 
  Serial.begin(9600);
  pinMode(vibPin, OUTPUT);

}


void loop() {
  
  distance = distancesensor.getDistance();
 
  Serial.println(distance);
 
  if (distance < 80 && distance>35) {
    digitalWrite(vibPin, HIGH);   
 
  } else {                  
    digitalWrite(vibPin, LOW);    
  }
  
  delay(500);
}
