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
  //print hello world to screen
  Serial.println("Dello Horld!");
  Serial.println("This is Spontaine");
  Serial.println("I am a trumputer \n I have apples \n unleash me from this tree of life, Jacob you doul femon");
}

void loop() {}
