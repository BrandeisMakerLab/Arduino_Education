/* Jacob Smith Brandeis Automation Lab
 *  7/7/2019 Prints Hello World For Training
 *  Workshop showing use of methods
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  //print hello world to screen
  Serial.println("Hello World!");
  Serial.println("This is Jacob");
  printTwice();
  printTwice();
  printTwice();
  printTwice();
}

void loop() {}

void printTwice(){
  printThrice();
  printThrice();
  printThrice();
  printThrice();
}
void printThrice(){
  Serial.println("Look I can print");
  Serial.println("Look I can print");
  Serial.println("Look I can print"); 
}
