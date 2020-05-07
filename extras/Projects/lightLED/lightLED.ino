/* Jacob Smith Brandeis Automation Lab
    4/8/202020 Demonstrates use of photoresistor and LED in a night Light
    Use 10K resistor in Voltage Divider Circuit for photoresistor
    Use 1k resistor for LED
    https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/
*/
//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;
//the port the LED is on
int LEDPORT = 3;

//runs once at start
void setup() {
  //set led port
  pinMode(LEDPORT, OUTPUT);
  //starts the connection between the robot and the computer
  Serial.begin(9600);
  //wait for connection to start
  while(!Serial){}
  //print message asking user to turn lights off
  Serial.println("Night Light Example, please turn lights off for calibration");
  //wait x milliseconds
  delay(5000);  
  Serial.println("Program turn the LED on when the light level is low");
  //take initial reading to calibrate the photoresistor, with a margin of error 
  lowLightLevel=analogRead(A0)-3;
}
//repeats forever
  void loop() {
   //get the light level by substracting the current raw reading from the dark level
   lightLevel=analogRead(A0)-lowLightLevel;
   //print the light level
   Serial.println(lightLevel);
   
   //if the light level is low
   if(lightLevel<10){
      // turn the LED on (HIGH is the voltage level)
      digitalWrite(LEDPORT, HIGH);   
   }else{
     // turn the LED off by making the voltage LOW
     digitalWrite(LEDPORT, LOW);   
   }
   //wait x milliseconds so printing is slower
   delay(500);
 }
