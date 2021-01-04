/* Jacob Smith Brandeis Automation Lab 4/8/202020 
*	Demonstrates use of photoresistor
*	If using onlnie simualtor, use with Calibration example
*   If building on your own, Use 10K resistor in Voltage Divider Circuit
*   Change the light level right after running the program and see how the reading changes! 
*   https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/
*/
//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;

//runs once at start
void setup() {
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  delay(1000);
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
   //wait x milliseconds so printing is slower
   delay(500);
 }
