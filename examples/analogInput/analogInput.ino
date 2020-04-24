/* Curated by Brandeis University
 *  Basic Analog read ,can be used with capacitive touch sensor
 *  https://makersportal.com/blog/2018/9/21/capacitive-touch-sensor-with-arduino
 */
//the current value of the input device  
long val;
//runs once to set things up for the loop
void setup() {
  //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  while(!Serial){}
  //print welcome message
  Serial.println("Analog Input Example Program"); 
}

//runs forever, main part of program
void loop(){
  //get the current value of that digitalPort
  val = analogRead(A0); 
  //print the value to the screen
  Serial.println(val);
  //wait half a second
  delay(500);
}


 
