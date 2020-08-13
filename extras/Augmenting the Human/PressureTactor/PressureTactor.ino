/* reads the pressure level, if pressure level is high vibrates vibrotactor

*/

//the port of the vibrator
int vibPin=6;
//variable which stores the low pressure level for calibration
int lowPressureLevel;
//variable which stores the current calibrated pressure level
int pressureLevel;

//runs once
void setup() {
  
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  while(!Serial){}
  pinMode(vibPin, OUTPUT);
  //print message asking user to turn pressures off
  Serial.println("Photoresistor/pressure Sensor Example, please turn pressures off for calibration");
  //wait x milliseconds
  delay(4000);  
  Serial.println("Program will print calibrated pressure level, try turning pressures on and off");
  //take initial reading to calibrate the photoresistor, with a margin of error 
  lowPressureLevel=analogRead(A0);
  //turn vibrator pin on to signal ready to measure
  digitalWrite(vibPin, HIGH); 
  //wait x milliseconds
  delay(500);
  //turn vibrator pin off
  digitalWrite(vibPin, LOW);
}

//runs many times
void loop() {
  //get the pressure level by substracting the current raw reading from the dark level
   pressureLevel=analogRead(A0)-lowPressureLevel;
   //print the pressure level
   Serial.println(pressureLevel);
  //vibrates if distance is within range
  if (pressureLevel > 0) {
    //turn tactor on 
    digitalWrite(vibPin, HIGH);   
  //otherwise turns fibrator off and waits x milliseconds
  } else {                
    //turn tactor off  
    digitalWrite(vibPin, LOW);    
  }
  //wait x milliseconds so pulse is percievable by human
  delay(500);
}
