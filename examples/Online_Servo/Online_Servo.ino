/* Curated by Jacob Smith for Brandeis Automation Lab 12/30/20
   Runs a servo motor
   Deliberately has 5 errors to practice programming
*/
//include the background library to use the servo
#include <Servo.h>
//name the servo to use it in the program
Servo servo;  

//how long the motor moves
int time =2000;

//runs once
void setup(){
  //attach motor at its port
  servo.attach(9);
}

//runs many times
 void loop(){
   //move the servo to a position
   servo.write(0);  
   //wait a certain amount of time    
   delay(time);     

   //move the servo to another position
   servo.write(180);
   //wait a certain amount of time
   delay(time);
}
