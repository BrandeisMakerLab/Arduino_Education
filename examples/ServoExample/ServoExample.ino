/*
Intro Server Tutorial from https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
Curated by Brandeis Automation Lab
*/
 
#include <Servo.h>  //add '<' and '>' before and after servo.h
 
int servoPin = 12;
int angle;
 
Servo servo;  

int time =1000;
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
}
 
 
void loop()
{
//control the servo's direction and the position of the motor
   servo.attach(servoPin);
   servo.write(0);      // Turn SG90 servo Left to 45 degrees
   delay(time);     
   
   servo.attach(servoPin);
   servo.write(180);
   delay(time);          // Wait 1 second

}
