/*
  Intro Server Tutorial from https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
  Curated by Brandeis Automation Lab
*/

#include <Servo.h>  //add '<' and '>' before and after servo.h
int pins []={5,6,7,8,9,11,12};

int pinkyFPin = 3;
int indexFPin = 4;
int thumbFPin = 2;
int ringFPin = 10;
int middleFPin = 13;
int angle;

Servo ringF;
Servo pinkyF;
Servo thumbF;
Servo indexF;
Servo middleF;

int servoAngle = 0;   // servo position in degrees
int time = 1000;
void setup()
{
  Serial.begin(9600);
 ringF.attach(ringFPin);
  middleF.attach(middleFPin);
  thumbF.attach(thumbFPin);
  pinkyF.attach(pinkyFPin);
  indexF.attach(indexFPin);

}


void loop()
{
 move2Fingers(middleF, 0, 50, indexF, thumbF, pinkyF, ringF);
 // moveFinger( thumbF, -100, 100);
  // moveFinger ( indexF, 0, 100);
   //moveFinger( middleF, 0, 100);
 //moveFinger( ringF, -100, 100);
// 
//  
 // moveFinger( pinkyF, 40, 60);

 

}

// Have a for loop within a for loop
void move2Fingers(Servo finger, int startPos, int endPos, Servo finger2, Servo finger3, Servo finger4, Servo finger5) {
  int pos;
 // for (pos = startPos; pos <= endPos; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    finger.write(75);    
     finger2.write(20);
     finger3.write(100);
     finger4.write(40);
     finger5.write(-100);
// tell servo to go to position in variable 'pos'
    delay(2000);                       // waits 15ms for the servo to reach the position
  //}

  //for (pos = endPos; pos >= startPos; pos -= 1) { // goes from 180 degrees to 0 degrees
    finger.write(30);              // tell servo to go to position in variable 'pos'
     finger2.write(90);
     finger3.write(-100);
     finger4.write(90);
     finger5.write(100);
    delay(4000);                       // waits 15ms for the servo to reach the position
 // }
//  int pos;
//  for (pos = startPos; pos <= endPos; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    finger.write(pos);    
//    finger2.write(pos);
//// tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//
//  for (pos = endPos; pos >= startPos; pos -= 1) { // goes from 180 degrees to 0 degrees
//    finger.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//
//      int pos2;
//  for (pos2 = startPos2; pos2 <= endPos2; pos2 += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    finger.write(pos2);    
//// tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//
//  for (pos2 = endPos2; pos2 >= startPos2; pos2 -= 1) { // goes from 180 degrees to 0 degrees
//    finger.write(pos2);              // tell servo to go to position in variable 'pos'
//    finger2.write(pos2);
//    delay(15); 
//  }
//  }
}


void moveFinger(Servo finger, int startPos, int endPos) {

  int pos;
  for (pos = startPos; pos <= endPos; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    finger.write(pos);    
// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = endPos; pos >= startPos; pos -= 1) { // goes from 180 degrees to 0 degrees
    finger.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
