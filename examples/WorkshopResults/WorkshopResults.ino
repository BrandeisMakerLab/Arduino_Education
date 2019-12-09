/*
 * Tarakaram.
 * This program measures distance once, if the distance is less than 10 units, it re
 * takes the distance until the distance is more than 10.
 * 
 * After that, it turns the LED on for last digit of distance seconds and brifly runs 
 * the motor based on the same last digit.
 */

#include <DistanceSensor.h>
#include <Servo.h>
//Display display;
//The object used to interfact with the class
DistanceSensor distancesensor;

int distance;
int servoPin = 12;
int PIN = 3;

Servo servo; 

void setup() {
  // put your setup code here, to run once:
distancesensor.begin(10,11);
Serial.begin(115200);
distance= distancesensor.getDistance();
servo.attach(servoPin);

// the setup function runs once when you press reset or power the board
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN, OUTPUT);
}

int dist(){

  distance= distancesensor.getDistance();
  return distance;
}

void loop() {
  // put your main code here, to run repeatedly:

  while (distance <= 9)
    {
      distance = dist();
       Serial.println("loop");
    }
  int led1;
  led1 = (distance % 10);
  Serial.print("distance is");
  Serial.println(distance);
  Serial.print("First digit is");
  Serial.println(led1);

  digitalWrite(PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000*led1);
  digitalWrite(PIN, LOW); 

  delay(1000);
  servo.write(led1);
  delay(1000);          // Wait 1 second


}
