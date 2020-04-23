/*4/22/20 Jacob Smith for Brandeis Automation Laboratory
 * Uses teh 5V relay to control any device
*/
//the port the relay is on
int PIN = 3;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin to the the specified number
  pinMode(PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // turn the relay on (HIGH is the voltage level)
  digitalWrite(PIN, HIGH);  
  // wait for x milliseconds
  delay(5000);
  // turn the relay off by making the voltage LOW                       
  digitalWrite(PIN, LOW);    
  // wait for x milliseconds    
  delay(5000);  
                    
}
