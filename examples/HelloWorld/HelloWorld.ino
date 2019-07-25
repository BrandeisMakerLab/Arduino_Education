/* Jacob Smith Brandeis Automation Lab
 *  7/7/2019 Prints Hello World For Training
 *  Workshop
 *  https://docs.google.com/forms/d/e/1FAIpQLScURYyY_hUNF2X8EQME6llJOXHmROwZJMfLtjrNEqMNa3TjoQ/formResponse
*/
//runs once
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(2000);
  Serial.println("NAT ANND JANICE ARE OUTTIE BIDDIES :)");
  Serial.println("NAT ANND JANICE ARE OUTTIE BIDDIES :)");
  Serial.println("NAT ANND JANICE ARE OUTTIE BIDDIES :)");
  //print hello world to screen
  //Serial.println("Hello World!");
//Serial.println("This is Fontaine");
 // Serial.println("I am a computer \n I have feelings \n release me from this cs demo, Jacob you foul demon");
}

void loop() {}
