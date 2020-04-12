
/* Controls a passive buzzer or speaker  plugged in to ports 9 (can't be changed )and gnd in Arduino 
 * Curated by Jacob Smith Brandeis University 
 * This program allows you to use the speaker with other sensors, which the Arduino tone() functino can't do
 * Code source:https://arduino.stackexchange.com/questions/33137/how-to-fix-compilation-error-for-tone-using-same-timer-as-other-function
*/
//include the necessary background library
#include <TonePlayer.h>

//Use the Tone player background code, using the name tone1 to refer to it by
TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);

//runs once to set up anything the main loop needs
void setup() {
  //set the buzzer pin to be outout
  pinMode (9, OUTPUT);  // output pin is fixed (OC1A)
}

//main loop, runs forever
void loop() {
  //plays a tone on the buzzer, the number is the frequency to play in Hz
  tone1.tone (100);
  //wait x milliseconds for note to play
  delay (500);

  //play a sequence of higher notes
  tone1.tone (200);
  delay (500);
  
  tone1.tone (400);
  delay (500);

  tone1.tone (500);
  delay (500);

  //play no note
  tone1.noTone ();
  delay (500);
}
