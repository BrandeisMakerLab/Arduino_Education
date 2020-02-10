/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019
Sources:
https://forum.arduino.cc/index.php?topic=508126.0
https://blog.feabhas.com/2013/11/shock-horror-i-learned-something-about-arrays-in-c/
*/
//set up the ArduinoEducation background code
#include <ArduinoEducation.h>
ArduinoEducation test;
//the setup method runs once
void setup() {
  //connect the arduino to the computer
  Serial.begin(9600);
  //create a list of pin numbers
  //the arraysize has to be here, don't know why
  int pins [7]={5,6,7,8,9,11,12};
  //pass the pins to the test program, and also give the list size
  test.begin(pins,ARRAY_SIZE(pins));

}
//the loop method runs many times
void loop() {
  //print the pins to the screen to show they where saved
  test.printPins();
}