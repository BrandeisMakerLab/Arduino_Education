/*https://www.youtube.com/watch?v=IKD5Jhyg_cc 
 * controls a passive buzzer plugged in to ports 11 and gnd in Arduino
 * Curated by Jacob Smith Brandeis University 
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
  //
  delay(time*2);
  tone(buzzerPin,400);
  delay(time*2);
  tone(buzzerPin,500);
  delay(time*2);
  noTone(buzzerPin);
  delay(time);
}
