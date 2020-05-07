/*Tactor Rig designed to convert ultrasonic distance sensor to tactile output on
a variety of modes. The modes are on/off, time, and encode.
Reads distance from an ultrasonic sensor Jacob Smith 2020/02/24*/

//includes the libraries of code necessary to make this one work
#include <TactorRig.h>
//Display display;
//The object used to interfact with the class
TactorRig tactorRig;

//runs once
void setup() {
  //sets up the class
  tactorRig.begin();
}

//runs many times
void loop() {
  //uncomment the mode you want to use
  //vibrate in Onn Off mode
  //tactorRig.vibrateOnOff();
  //vibrate in Encode mode
  //tactorRig.vibrateEncode();
  //vibrate in time Mode
  tactorRig.vibrateTime();
}
