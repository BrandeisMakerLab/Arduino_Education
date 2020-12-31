/* Jacob Smith Brandeis Automation Lab7/7/2019 
	Shows how printing to screen works on Arduino
	Use with any example in online simulator
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  //print message once
  Serial.println("Hello World!");  
  //wait x milliseconds
  delay(500);

}
  void loop() {
   //print message to repeat
   Serial.println("Hi");
   //wait x milliseconds so print is slowed down
   delay(100);
 }
