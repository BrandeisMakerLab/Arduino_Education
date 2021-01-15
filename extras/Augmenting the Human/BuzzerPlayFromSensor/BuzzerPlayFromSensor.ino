/* Written by Jacob Smith for Technology Research Group 1/14/21
    Plays the notes of a scale based on a sensor reading
    sources https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

//the digital port the buzzer is in
int buzzerPin = 8;

//what port the analog sensor is plugged in to
int inPin = A0;

//the minimum and maximum possible sensor values
int INPUT_MIN=300;
int INPUT_MAX=560;

//the value of the sensor
int sensorVal;

//the the current note to play
int note;

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
  Serial.println("Will play the scale then notes from sensor reading");
  // declare that port as an input
  pinMode(buzzerPin, OUTPUT);

  //play notes low to high
  for (int i = 0; i < 16; i++) {
    //print what note is being played
    Serial.print("Playing Note: ");
    Serial.println(i);
    //play that note for half the measure
    tone(buzzerPin, notes[i]);
    delay(500);
  }
  //stop playing for two measures
  noTone(buzzerPin);
  delay(2000);
}

//runs forever, main part of program
void loop() {
  //get the sensor value
  sensorVal=analogRead(inPin);
  //print the sensor value
  Serial.print("Sensor Reading is:\t");
  Serial.println(sensorVal);
  //get what noet to play by calculating the nearest note to the sensor reading
  note=map(sensorVal,INPUT_MIN,INPUT_MAX,0,17);
  //make sure note is within the listed notes, not too high
  note=constrain(note,0,16);
  //print the note
  Serial.print("\tNote is:\t");
  Serial.println(note);
  
  tone(buzzerPin,notes[note]);
  delay(250);
  
}
