/*
 * This program detects whenever a new min or max distance from the distance sensor is reached.
 * A motor is turned and a light flashes whenever this happens to alert the user.
 * 
 * A possible application is if you're tracking the movement of lab mice, for example, and you
 * want to be alerted if they travel past a set boundary so you can move them back in.
 * 
 * Ryan Xu
 * 8/4/19
 * 
 */

#include <Servo.h>  //add '<' and '>' before and after servo.h
#include <DistanceSensor.h>

DistanceSensor distancesensor;
Servo servo;

//input pin numbers
int ledPin = 3;
int servoPin = 9;
int distancePin = 11;

int distance;
int min;
int max;
boolean angle;


//runs once
void setup() {
  
    //sets up the class
    distancesensor.begin(10, 11);
    Serial.begin(9600);
    
    servo.attach(servoPin);
    pinMode(ledPin, OUTPUT);
    pinMode(distancePin, INPUT);
    min = distancesensor.getDistance();
    max = distancesensor.getDistance();
    digitalWrite(ledPin, LOW);
    
    Serial.println("This program detects whenever a new min or max distance from the distance sensor is reached. Yay!!");
    Serial.println("Oh, and a light blinks each time it happens!!!\nand a motor rotates\nfor some reason.\n");
}

//runs many times
void loop() {
    //gets the distance from the ultrasonic sensor
    distance = distancesensor.getDistance();

    //update min distance
    if (distance < min) {
       changeDistance(false);
    }

    //update max distance
    if (distance > max) {
        changeDistance(true);
    }
}

/* Updates either the min or max distance depending on the passed
parameter and prints a message out to the console and rotates the
motor 180 deegres.
*/
void changeDistance(boolean type) {
    digitalWrite(ledPin, HIGH);
    if (!type) {
        min = distance;
        rotate();
        Serial.print("New min distance: ");
        Serial.println(min);
    } else {
        max = distance;
        rotate();
        Serial.print("New max distance: ");
        Serial.println(max);
    }
    digitalWrite(ledPin, LOW);
}

/* Rotates the motor 180 degrees */
void rotate() {
    if (angle) {
        servo.write(0);
        angle = !angle;
    } else {
        servo.write(180);
        angle = !angle;
    }
    delay(1000);
}
