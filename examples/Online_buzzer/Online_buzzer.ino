/* Curated by Jacob Smith Brandeis University 
 * controls a passive buzzer plugged in buzzerPin and gnd in Arduino
 * Use with Tone melody in online simulator
 *
*/
//the digital port the buzzer is in
int buzzerPin=8;
//how long each note will be
int time=500;
//runs once to set up program
void setup() {
  //specifies that the speaker port will be an output
   pinMode(buzzerPin, OUTPUT);
}
//runs many times
void loop() {
  //plays a tone on the buzzer, the number is the note to play
  tone(buzzerPin,300);
  //wait for the time amount times something
  delay(time*2);
  tone(buzzerPin,400);
  delay(time*2);
  tone(buzzerPin,500);
  delay(time*2);
  noTone(buzzerPin);
  delay(time);
}
