/*Into Robotics Tutorial from https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/ 2019/09/19*/

//includes the libraries of code necessary to make this one work
#include <ServoExample.h>

//The object used to interfact with the class
ServoExample servoexample();

//TODO: EXPLAIN WHAT METHOD DOES
void setup() {
    //sets up the class
    servoexample.begin();
    Serial.begin(9600);  
    servo.attach(servoPin);

}

//TODO: EXPLAIN WHAT METHOD DOES
void loop() {
    //control the servo's direction and the position of the motor
     servo.write(102);      // Turn SG90 servo Left to 45 degrees
     delay(time);     
     delay(time);// Wait 1 second
     servo.write(40);      // Turn SG90 servo back to 90 degrees (center position)
     delay(time);          // Wait 1 second
     
     //servo.write(170);     // Turn SG90 servo Right to 135 degrees
    // delay(time);          // Wait 1 second
     //servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
     //delay(time);
    //end control the servo's direction and the position of the motor
    /*
    servo.write(angle);
    delay(time);
    angle = (angle + 1) % 180;
    */

}

