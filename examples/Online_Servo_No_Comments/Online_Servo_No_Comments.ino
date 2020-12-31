/* Curated by Jacob Smith for Brandeis Automation Lab 12/30/20
   Runs a servo motor
   Deliberately has no comments to practice commenting
*/

#include <Servo.h>

Servo servo;  


int time =2000;


void setup(){
  
  servo.attach(9);
}


 void loop(){
   
   servo.write(0);  
   
   delay(time);     

   
   servo.write(180);

   delay(time);
}
