/* reads the light level, if light level is high vibrates vibrotactor
    This version vibrates faster for higher levels of light
    Brandeis Augmenting the Human Iniative 5/14/2020 Jacob Smith
*/

//the port of the vibrator
int vibPin=2;
//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;
//converts light level to appropriate time to pulse
int SCALING_FACTOR=16;
//estimate of max light level so time response function can be created
int MAX_LIGHT=40;
//runs once
void setup() {
  
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  while(!Serial){}
  pinMode(vibPin, OUTPUT);
  //print message asking user to turn lights off
  Serial.println("Photoresistor/Light Sensor Example, please turn lights off for calibration");
  //wait x milliseconds
  delay(4000);  
  Serial.println("Program will print calibrated light level, try turning lights on and off");
  //take initial reading to calibrate the photoresistor, with a margin of error 
  lowLightLevel=analogRead(A0)-3;
  //turn vibrator pin on to signal ready to measure
  digitalWrite(vibPin, HIGH); 
  //wait x milliseconds
  delay(500);
  //turn vibrator pin off
  digitalWrite(vibPin, LOW);
}

//runs many times
void loop() {
  //get the light level by substracting the current raw reading from the dark level
   lightLevel=analogRead(A0)-lowLightLevel;
   //print the light level
   Serial.println(lightLevel);
  //vibrates if distance is within range
  if (lightLevel > 10) {
    //turn vibrator on
    digitalWrite(vibPin, HIGH); 
    //use this equation to determine how long pulse is
    //pulses faster if light level is higher
    delay(MAX_LIGHT*SCALING_FACTOR-lightLevel*SCALING_FACTOR);  
    //turn tactor off
    digitalWrite(vibPin, LOW); 
    //same function as above
    delay(MAX_LIGHT*SCALING_FACTOR-lightLevel*SCALING_FACTOR);  
  }   
}
