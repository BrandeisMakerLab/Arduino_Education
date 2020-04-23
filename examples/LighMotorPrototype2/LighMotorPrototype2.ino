/* Jacob Smith Brandeis Automation Lab
    4/22/202020 Demonstrates prototype that jerks motor if light level changes
*/
//include the library needed to run the servo 
//how long the motor moves
int time =100;

//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;

//save the port number  
  int PIN = 3;
  
//runs once at start
void setup() {
  //attach motor
  pinMode(PIN,OUTPUT);
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  while(!Serial){}
  //print message asking user to turn lights off
  Serial.println("Photoresistor/Light Sensor Example, please turn lights off for calibration");
  //wait x milliseconds
  delay(3000);  
  Serial.println("Program will print calibrated light level, try turning lights on and off");
  //take initial reading to calibrate the photoresistor, with a margin of error 
  lowLightLevel=analogRead(A0)-3;
}
//repeats forever
  void loop() {
   //get the light level by substracting the current raw reading from the dark level
   lightLevel=analogRead(A0)-lowLightLevel;
   //print the light level
   Serial.println(lightLevel);

   if(lightLevel>6){
      digitalWrite(PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
   
 }
