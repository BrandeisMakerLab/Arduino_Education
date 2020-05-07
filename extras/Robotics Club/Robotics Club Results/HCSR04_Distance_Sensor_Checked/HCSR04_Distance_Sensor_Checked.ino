/* Legally plagiarised from
 * https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
 * By Nathaniel B Rowe and Matthew Merovitz
 * I recommend you actually download the NewPing library from the
 * above link.
 * Enjoy responsibly
 * Inspired by Jacob Smith
 */

//includes the libraries of code necessary to make this one work
#include <DistanceSensor.h>
//The object used to interfact with the class
DistanceSensor distancesensor;

double distance;

byte trigPin = 6; //Change as necessary
byte echoPin = 2; //Change as necessary
long duration, cm, inches;

void setup() {
  distancesensor.begin(trigPin, echoPin);
  Serial.begin(9600); // For monitoring purposes
}

void loop() {

  // Send a low pulse to ensure a clean high pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read pulse
  duration = pulseIn(echoPin, HIGH);

  // Halve the duration to account for reflection (sound bounced back)
  cm = (duration/2) / 29.1; // (speed of sound is 1/29.1 cm/uS)
  inches = (duration/2) / 74; // (speed of sound is 1/74 in/uS)

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(200); // The length of this delay isn't important
}
