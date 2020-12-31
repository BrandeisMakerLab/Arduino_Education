/* Jacob Smith Brandeis Automation Lab 7/7/2019 
 *  Prints a message many times using methods
 *  Use with any example in online simulator
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  //print hello world to screen
  Serial.println("Hello World!");
  
  //run the printTwice method
  printTwice();
  printTwice();
  printTwice();
  printTwice();
}

//not used here
void loop() {}

//method which only runs printThrice method
void printTwice(){
  printThrice();
  printThrice();
  printThrice();
  printThrice();
}
//mthod which prints to screen three times
void printThrice(){
  Serial.println("Look I can print");
  Serial.println("Look I can print");
  Serial.println("Look I can print"); 
}
