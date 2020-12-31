/* Curated by Jacob Smith for Brandeis Automation Lab 12/30/20
  Demonstrates use of Ultrasonic Sensor in Online Simulator
  Use printDistance if building in person
  Interact with the distance sensor and see how the readout changes!
  From http://www.arduino.cc/en/Tutorial/Ping
*/

//a variable to store the distance from the ultrasonic sensor
//double means it will have a decimal point
double distance;

//runs once
void setup()
{
  //connect to the computer and print message
  Serial.begin(9600);
  Serial.println("Will Print Distance");
}

//runs forever
void loop()
{
  // measure the ping time in cm, .01723 is from speed of sound
  //7 is what port the sensor is plugged in to
  distance = 0.01723 * readUltrasonicDistance(7, 7);
  //print distance
  Serial.print(distance);
  Serial.println("cm");
  // Wait for 100 millisecond(s)
  delay(100); 
}

//runs the ultrasonic sensor, not neceessary to understand how this works
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}