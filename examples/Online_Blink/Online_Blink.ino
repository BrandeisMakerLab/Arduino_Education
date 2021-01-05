/*
  LED code from http://www.arduino.cc/en/Tutorial/Blink
  Use 1k-220 ohm resistor if using LED
*/
//the port the LED is on
int PIN = 13;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(PIN, HIGH);
  // wait for x milliseconds
  delay(1000);  
  // turn the LED off by making the voltage LOW
  digitalWrite(PIN, LOW); 
  // wait for x millisecondsd
  delay(1000);                     
}
