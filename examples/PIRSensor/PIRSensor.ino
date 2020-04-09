/*Arduino PIR (Heat) Sensor code
   Curated by Jacob Smith for Brandeis University Automation Lab
   Code from https://www.circuitmagic.com/arduino/pir-motion-sensor-with-arduino/
  https://forum.mysensors.org/topic/3287/motion-sensor-triggering-on-its-own/24
*/

//the digital pin connected to the PIR sensor's output
int pirPin = 11;
//if the sensor was triggered once
boolean trippedFirst;
//if the sensor was triggered twice
//checking twice makes reading more realiable
boolean trippedSecond;

//runs once at beginning of program
void setup() {
  //start usb connection
  Serial.begin(9600);
  //set sensor port to be an input
  pinMode(pirPin, INPUT);
  //set sensor port to low to calibrate
  digitalWrite(pirPin, LOW);

  //print intro message
  Serial.println("PIR (Heat) Sensor Demonstration");
  Serial.println("calibrating sensor");
  //wait x milliseconds so sensor can calibrate
  delay(30000);
  //print listneing message
  Serial.println("Listening");
}

//runs continously
void loop() {
  //chck if pir sensor is tirggered once
  trippedFirst = digitalRead(pirPin);
  //wait so checks are at different enough times
  delay(100);
  //check if pir sensor is tirggered twice
  trippedSecond = digitalRead(pirPin);
  //use if statement to see if snesor was tripped first time and second time, then do what's in brackets
  if (trippedFirst && trippedSecond) {
    //print found message to screen
    Serial.println("Found");
    //wait for sensor to stop being triggered
    while (digitalRead(pirPin) == HIGH) {}
    //wait an extra x miliseconds so sensor won't false trigger
    delay(2000);
    //print that sensor is listening
    Serial.println("Listening");
  }
}
