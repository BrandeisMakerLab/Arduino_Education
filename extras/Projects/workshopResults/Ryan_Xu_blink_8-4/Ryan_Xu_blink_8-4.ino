/*
  Used blink file as an electronics example.
  This program has the light start blinking every two seconds and decreases the
  time difference between each blink until the light is constant.
  Also prints the time difference out
*/

double time = 1000;
boolean status = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(time);
  if (status) {
    digitalWrite(2, HIGH);
    status = !status;
  } else {
    digitalWrite(2, LOW);
    status = !status;
  }
  delay(time);
  time = time / 1.05;
}
