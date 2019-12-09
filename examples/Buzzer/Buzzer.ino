/*https://www.youtube.com/watch?v=IKD5Jhyg_cc 
 * controls a passive buzzer plugged in to ports 11 and gnd in Arduino
*/
int buzzerPin=11;
int time=500;
void setup() {
  // put your setup code here, to run once:

}
void loop() {
  tone(buzzerPin,300);
  delay(time*2);
  tone(buzzerPin,400);
  delay(time*2);
  tone(buzzerPin,500);
  delay(time*2);
  noTone(buzzerPin);
  delay(time);
}
