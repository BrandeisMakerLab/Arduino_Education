/*Jacob Smith for Brandeis Makerlab 8/7/2019
 * Demonstrated use of an if statement to print to screen
 * Use with any example in online simulator
 * Change variable from true to false and see what changes!
 */
//runs once
void setup() {
  //starts up connection to screen
  Serial.begin(9600);
  delay(2000);
  //set up a true or false variable
  bool variable = true;
  //if variable is true print it was true
  if (variable) {
    Serial.println("Var was true");
   //if var was fals,e print it was false
  } else {
    Serial.println("Var was false");
  }
}

//not used
void loop() {}
