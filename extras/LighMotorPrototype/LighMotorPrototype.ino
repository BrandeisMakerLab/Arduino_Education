/* Jacob Smith Brandeis Automation Lab
    4/22/202020 Demonstrates prototype that jerks motor if light level changes
*/
//include the library needed to run the servo
#include <Servo.h>  //add '<' and '>' before and after servo.h
//name the servo
Servo servo;  
//how long the motor moves
int time =100;

//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;

//runs once at start
void setup() {
  //save the port number  
  int number = 11;
  //attach motor
  servo.attach(number);
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

   if(lightLevel>5){
     //move the servo to a position
    servo.write(0);  
    //wait a certain amount of time    
    delay(time);     

    //move the servo to another position
    servo.write(180);
    //wait a certain amount of time
    delay(time);
    //wait x milliseconds so printing is slower
    }
   
 }
