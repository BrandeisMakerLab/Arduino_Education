/*  Example program for waterbot written by Jacob Smith 2/14/20
 *  allows the waterbot to navigate through a pool, not tested in water
 *  https://www.kickstarter.com/projects/slantrobotics/waterbot-arduino-water-robotics-kit
*/

//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>

#include <Servo.h>
//The object used to interfact with the class
DistanceSensor distancesensor;

//the distance to the sensor
double distance;

int power=180;
Servo leftPaddle;  // create servo object to control a servo
Servo rightPaddle;
//runs once
void setup() {
  //sets up the class
  //Echo and trig on pcb board
  distancesensor.begin(A3,A2);
   //S1 on Meped Littlebot control board
  leftPaddle.attach(2);
  //S2 on Meped Littlebot control board
  rightPaddle.attach(3);
  //initialzie serial connection
   Serial.begin(9600);
    
   //show initial swim moves
   swimForward(1000);
   swimStop(500);
   swimBackward(1000);
   swimStop(500);
   swimRight(1000);
   swimStop(500);
   swimLeft(1000);
   swimStop(500);
   swimStop(500);
   Serial.println("Waterbot Test Program");
   Serial.println("Navigates around pool");
   Serial.println("Prints distance in cm and whether wall was found"); 
}

//runs many times
void loop() {
  //gets the distance from the ultrasonic sensor
  distance=distancesensor.getDistance();
  //displays the distance to the ultrasonic sensor
  Serial.print(distance);
  if(distance<5 && distance>0){
      Serial.print("\tFound Wall");
      swimBackward(1000);
      swimStop(1000);
      swimRight(2000);
      swimStop(500);
  }else{
   swimForward(0);
  }
  Serial.println();
}

void swimForward(int time){
  leftPaddle.write(125); 
  rightPaddle.write(55);
  delay(time);
}

void swimBackward(int time){
  leftPaddle.write(45); 
  rightPaddle.write(135);
  delay(time);
}
void swimRight(int time){
  leftPaddle.write(135); 
  rightPaddle.write(135);
  delay(time);
}

void swimLeft(int time){
   leftPaddle.write(45); 
  rightPaddle.write(45);
  delay(time);
  
}

void swimStop(int time){
   leftPaddle.write(90);
   rightPaddle.write(90);
   delay(time);
}
