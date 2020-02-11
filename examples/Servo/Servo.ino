/*
Intro Server Tutorial from https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
Curated by Brandeis Automation Lab
*/
//include the library needed to run the servo
#include <Servo.h>  //add '<' and '>' before and after servo.h
//name the servo
Servo servo;  

//how long the motor moves
int time =1000;
//runs once
void setup()
{
  //establish serial connection
  Serial.begin(9600);  
  //save the port number  
  int number = 12;
  //attach motor
  servo.attach(number);
}
//runs many times
 void loop()
{
   //move the servo to a position
   servo.write(0);  
   //wait a certain amount of time    
   delay(time);     

   //move the servo to another position
   servo.write(180);
   //wait a certain amount of time
   delay(time);
}
