/* Display Class for use in earthmake lcd
   https://github.com/earthmake/arLCD/issues/2
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
//#include <Display.h>
//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//The object used to interfact with the class
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
  Serial.begin(9600); pinMode(2, OUTPUT);
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance = distancesensor.getDistance();
  //displays the distance to the ultrasonic sensor
  //display.showMeter("Distance",distance);
  Serial.println(distance);
  if (distance > 00 && distance < 100) {
    Serial.println("close");  
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }else{
     digitalWrite(2, LOW);   // turn the LED off (HIGH is the voltage level)
    }
  delay(100);
}
