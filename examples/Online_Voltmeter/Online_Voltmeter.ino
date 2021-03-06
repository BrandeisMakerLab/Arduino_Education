/* Jacob Smith for Brandeis Automation Lab 1/5/20
  Uses the Arduino as a voltmeter to measure the voltage in 
    an LED blink example
*/
//the port the LED is on
int PIN = 13;
//the current value of the input device  
long val;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN, OUTPUT);
   //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  delay(2000);
  //print welcome message
  Serial.println("Voltmeter Example Program"); 
}

// the loop function runs over and over again forever
void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(PIN, HIGH);
  // wait for x milliseconds
  delay(1000);  
  
   //get the current value of that analog port
  val = analogRead(A0); 
  //print the value to the screen
  Serial.println(val*5.0/1023);
  
  // turn the LED off by making the voltage LOW
  digitalWrite(PIN, LOW); 
  // wait for x millisecondsd
  delay(1000);
  
 
}
