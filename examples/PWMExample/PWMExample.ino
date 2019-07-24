/*
  Fade 
  Brandeis Electronics Workshop
  Moified from Public ade Example
  cycles through light dimness wich is connected to port 3
*/

int led = 3;           // the PWM pin the LED is attached to
int maxBrightness = 200;    // how bright the LED is

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  for (int i = 0; i < maxBrightness; i++) {
    analogWrite(led,i);
    delay(10);
  }
}
