/* Curated by Brandeis University
 *  Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 * https://www.arduino.cc/en/tutorial/pushbutton
 *
 */

int inPin = 7;   // choose the input pin (for a pushbutton)
bool val;
void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);    // declare pushbutton as input
}

void loop(){
  val = digitalRead(inPin);  // read input value
  Serial.println(val);
  delay(500);
}
 
