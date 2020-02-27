/*Joystick Example Program
 * https://www.instructables.com/id/Arduino-37-in-1-Sensors-Kit-Explained/
 * Curated Jacob Smith Brandeis University
*/

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
 
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  Serial.println("Switch\tX-Axis\t Y Axis");
}
 
void loop() {
  Serial.print(digitalRead(SW_pin));
  Serial.print("\t");
  Serial.print(analogRead(X_pin));
  Serial.print("\t");
  Serial.println(analogRead(Y_pin));
  delay(5000);
}
