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
  move(); 
}
  void loop() {}


  void move() {
    moveforward(30);
    bool dark =true;
    if (dark) {
      pivotright(90);
      moveforward(30);
    }
    if (dark) {
      pivotleft(90);
      moveforward(30);
    }

    dark = false;
    // blink light
    // digitalWrite(led, HIGH);
    // digitalWrite(led, LOW);
    //loop move toward the light forward
    //
    //
    // while senses dark
    // digitalWrite(led, HIGH);
    // move();
    //
    //if senses light more than blah blah amount
    //stop for 5 seconds
    //digitalWrite(led, LOW);

  }
  void moveforward(int angle) {
    Serial.print("imoveforward");
    Serial.println(angle);
  }
  void pivotright(int angle) {
    Serial.print("ipivotright");
    Serial.println(angle);
  }
  void pivotleft(int angle) {
    Serial.print("ipivotleft");
    Serial.println(angle);
  }
