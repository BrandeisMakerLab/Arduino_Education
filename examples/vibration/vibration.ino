/*   Prepared for by Jacob Smith for Brandeis Automation Labrotaory 5/1/20 
 *   Prints data from the vibration sensor to the serial monitor
 *   https://www.youtube.com/watch?v=2pc2ehkSEAI */
//the port of the vibration sensor
int sensorPort =7; 
//the vibration level
long vibration; 
//runs once to setup program
void setup(){
  //connect to computer via USB
  Serial.begin(9600);
  //wait for USB connection
  while (!Serial){}
  //print intro message
  Serial.println("Vibration Sensor Example Program");
  Serial.println("Tap the table and see the results");
  //set the vibration sensor port as input
  pinMode(sensorPort, INPUT); 
}

//runs forever, main part of program
void loop(){
  //get the vibration level from the sensor 
  vibration =pulseIn (sensorPort, HIGH);
  //print vibration level to screen
  Serial.println(vibration);
  //wait x milliseconds so printing is slower
  delay(100);
}
