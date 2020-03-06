/* Jacob Smith Brandeis Automation Lab
    7/7/2019 Prints Hello World For Training
    Workshop
    https://docs.google.com/forms/d/e/1FAIpQLScURYyY_hUNF2X8EQME6llJOXHmROwZJMfLtjrNEqMNa3TjoQ/formResponse
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  Serial.println("Hello World!");   

}
  void loop() {
   Serial.println("Hi");
 }
