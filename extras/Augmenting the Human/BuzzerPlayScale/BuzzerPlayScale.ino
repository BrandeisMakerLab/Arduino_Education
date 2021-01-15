/* Written by Jacob Smith for Technology Research Group 1/14/21
    Plays the notes of a scale on the buzzer first low to thigh and then in a random order
    sources https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

//the digital port the buzzer is in
int buzzerPin = 8;

//how long each measure is in ms
int bar = 600;

//define the value to play to make that note
#define NOTE_A2  110
#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

//the list of notes in the a minor pentatonic scale
int notes[] = {NOTE_A2 , NOTE_C3 , NOTE_D3 , NOTE_E3 , NOTE_G3 , NOTE_A3 , NOTE_C4 , NOTE_D4 , NOTE_E4 , NOTE_G4 ,
               NOTE_A4 , NOTE_C5 , NOTE_D5 , NOTE_E5 , NOTE_G5 , NOTE_A5 , NOTE_B5
              };

//runs once to set things up for the loop
void setup() {
  //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  delay(1000);
  //print welcome message
  Serial.println("Buzzer Music Example Program ");
  Serial.println("Will play the scale then random notes");
  // declare that port as an input
  pinMode(buzzerPin, OUTPUT);

  //play notes low to high
  for (int i = 0; i < 16; i++) {
    //print what note is being played
    Serial.print("Playing Note: ");
    Serial.println(i);
    //play that note for half the measure
    tone(buzzerPin, notes[i]);
    delay(bar * 2);
  }
  //stop playing for two measures
  noTone(buzzerPin);
  delay(bar * 2);
}

//runs forever, main part of program
void loop() {
  //play a random note in the scale for half a measure
  //this works by selecting a random index of the list of notes
  tone(buzzerPin, notes[random(16)]);
  delay(bar / 2);

  //play a random note in the scale for half a measure
  tone(buzzerPin, notes[random(16)]);
  delay(bar / 2);
}
