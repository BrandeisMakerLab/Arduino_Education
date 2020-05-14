/* reads the light level, if light level is high vibrates vibrotactor
    This version vibrates to encode the light output
    So vibrating 3 times is light level 30
    Brandeis Augmenting the Human Iniative 5/14/2020 Jacob Smith
*/

//the port of the vibrator
int vibPin=2;
//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;
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
}

//runs many times
void loop() {
  //get the light level by substracting the current raw reading from the dark level
   lightLevel=analogRead(A0)-lowLightLevel;
   //print the light level
   Serial.println(lightLevel);
  //repeat x times to encode the output
  //so if light level is 25, vibrates twice (rounds down)
  for(int i=10;i<lightLevel;i+=10){
    //turn vibrator on
    digitalWrite(vibPin, HIGH); 
    //pulses faster if light level is higher
    delay(200);  
    //turn tactor off
    digitalWrite(vibPin, LOW); 
    //same function as above
    delay(200);    
  }   
  //wait x milliseconds to space out the information 
  delay(1000);
  }   
