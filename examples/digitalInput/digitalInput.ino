/* Curated by Brandeis University
 *  Basic Digital Read, can be used with button,  tilt switch, and water sensor
 * code source https://www.arduino.cc/en/tutorial/pushbutton
 */
// choose the input pin (for a pushbutton)
int inPin = 7; 
//the current value of the input device  
bool val;
//runs once to set things up for the loop
void setup() {
  //connect to the computer (at baud rate 9600)
  Serial.begin(9600);
  //wait for computer to connect
  while(!Serial){}
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
  //wait half a second
  delay(500);
}

 
