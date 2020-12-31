/*Brandeis Automation Lab
  Controls a light at no, medium, and high levels
  Use with Blink example in online simulator, but change the port to the number at line 7
  Moified from Public Fade Example
*/

// the PWM pin the LED is attached to
int led = 11;           

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //turn light on at no power
  analogWrite(led,0);
  //wait x miliseconds
  delay(2000);
  
  //turn light on at half power
  analogWrite(led,127);
  //wait x miliseconds
  delay(2000);
  
  //turn light on at full power
  analogWrite(led,255);
  //wait x miliseconds
  delay(2000);
}
