/* Jacob Smith Brandeis Automation Lab 7/7/2019 .
*  Prints message showing use of methods
*  Run in any example on online simulator 
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  //print hello world to screen
  Serial.println("Hello World!");
  //run the printTwice Method
  printTwice();
}
//not used
void loop() {}

//prints a message twice to screen
void printTwice(){
  Serial.println("Look I can do this now");
  Serial.println("Look I can do this now");
}
