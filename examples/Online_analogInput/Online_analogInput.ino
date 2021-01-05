/* Curated by Brandeis University
 *  Basic Analog read ,can be used with capacitive touch sensor or potentiometer (dial)
 *  Run the program and then try to make the values change by interacting with the sensor!
 *  https://makersportal.com/blog/2018/9/21/capacitive-touch-sensor-with-arduino
 *  https://www.youtube.com/watch?v=n7WRi5U5lQk
 */
//the current value of the input device  
long val;
//runs once to set things up for the loop
void setup() {
  //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  delay(2000);
  //print welcome message
  Serial.println("Analog Input Example Program"); 
}

//runs forever, main part of program
void loop(){
  //get the current value of that analog port
  val = analogRead(A0); 
  //print the value to the screen
  Serial.println(val);
  //x millisceonds
  delay(100);
}



 
