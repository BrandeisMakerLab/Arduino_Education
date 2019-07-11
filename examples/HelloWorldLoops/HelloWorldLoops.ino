/* Jacob Smith Brandeis Automation Lab
 *  7/7/2019 Prints Hello World For Training
 *  Workshop showing use of loops
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
}

void loop() {
  Serial.println("Hello World!");
}
