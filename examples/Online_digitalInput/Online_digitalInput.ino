/* Curated by Brandeis University
 *  Basic Digital Read, can be used with button,  tilt switch, and water sensor
 *  use with button example in online simulator 
 *  code source https://www.arduino.cc/en/tutorial/pushbutton
 */
// choose the input pin (for a pushbutton)
int inPin = 2; 
//the current value of the input device  
bool val;
//runs once to set things up for the loop
void setup() {
  //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  delay(1000);
  //print welcome message
  Serial.println("Digital Input Example Program");
  // declare that port as an input
  pinMode(inPin, INPUT);   
}

//runs forever, main part of program
void loop(){
  //get the current value of that digitalPort
  val = digitalRead(inPin); 
  //print the value to the screen
  Serial.println(val);
  //wait x milliseconds
  delay(100);
}

 
