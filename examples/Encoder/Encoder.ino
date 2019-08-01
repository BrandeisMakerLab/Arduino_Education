#define DOGLCD_CS       16
#define DOGLCD_MOSI     17
#define DOGLCD_SCK      23
#define BTN_EN1         31
#define BTN_EN2         33
#define BTN_ENC         35
#define SD_DETECT_PIN   49
#define SDSS            53
#define BEEPER_PIN      37
#define KILL_PIN        41

int cw,ccw,ok;
int encoderPos = 1;                     //Current encoder position
int encoder0PinALast;                   //Used to decode rotory encoder, last value
int encoder0PinNow;                     //Used to decode rotory encoder, current value

void setup() {
  // put your setup code here, to run once:
  pinMode(KILL_PIN, INPUT);             // Set KILL_PIN as an unput
  digitalWrite(KILL_PIN, HIGH);         // turn on pullup resistors
  pinMode(BTN_EN1, INPUT);              // Set BTN_EN1 as an unput, half of the encoder
  digitalWrite(BTN_EN1, HIGH);          // turn on pullup resistors
  pinMode(BTN_EN2, INPUT);              // Set BTN_EN2 as an unput, second half of the encoder
  digitalWrite(BTN_EN2, HIGH);          // turn on pullup resistors
  pinMode(BTN_ENC, INPUT);              // Set BTN_ENC as an unput, encoder button
  digitalWrite(BTN_ENC, HIGH);          // turn on pullup resistors
  Serial.begin(9600);
}

void loop() {

//  cw = digitalRead(BTN_EN1);
//  ccw = digitalRead(BTN_EN2);
//  
//  
//  Serial.print(cw);
//  Serial.print(",");
//  Serial.println(ccw);

//-----------------------------------

//  Serial.print(encoderPos);
//  Serial.print(",");
//  Serial.print(digitalRead(BTN_ENC));
//  Serial.print(",");
//  Serial.println(digitalRead(KILL_PIN));
//  
//  encoder0PinNow = digitalRead(BTN_EN1);
//  if ((encoder0PinALast == LOW) && (encoder0PinNow == HIGH)) {
//    if (digitalRead(BTN_EN2) == LOW) {
//      encoderPos++;
//    } else {
//      encoderPos--;
//    }
//  }
//  encoder0PinALast = encoder0PinNow;

//------------------

  cw =0;
  ccw =0;
  encoder0PinNow = digitalRead(BTN_EN1);
  if ((encoder0PinALast == LOW) && (encoder0PinNow == HIGH)) {
    if (digitalRead(BTN_EN2) == LOW) {
      //encoderPos++;
      cw = 1;
    } else {
      //encoderPos--;
      ccw = 1;
    }
  }
 encoder0PinALast = encoder0PinNow;
 delay(10);
  if (cw == 1){
    Serial.println("cw");
  }
  if (ccw == 1){
    Serial.println("ccw");
  }
}
