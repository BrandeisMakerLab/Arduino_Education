/*
Into Robotics Tutorial from https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
*/
 
#include <Servo.h>  //add '<' and '>' before and after servo.h
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees
int time =5000;
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
}
 
 
void loop()
{
//control the servo's direction and the position of the motor
 
   servo.write(45);      // Turn SG90 servo Left to 45 degrees
   delay(time);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(time);          // Wait 1 second
   servo.write(135);     // Turn SG90 servo Right to 135 degrees
   delay(time);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(time);
 
//end control the servo's direction and the position of the motor
}
