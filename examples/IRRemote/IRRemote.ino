/* Infrared Remote Sensor Demonstration
   Curated by Jacob Smith for Brandeis University Automation Lab
   From:https://www.instructables.com/id/Arduino-Infrared-Remote-tutorial/
   and https://forum.arduino.cc/index.php?topic=119545.0
   This uses the reomte included in the keeyess 16 sensor kit,
   other remotes will have different codes
*/
//the infrared remote background library
#include <IRremote.h>
//create a new infrared sensor object with specified sensor port
IRrecv irrecv(11);
//decode results object (this sensor is complicated)
decode_results results;
//runs once to set up program
void setup()
{
  //initializes connection with Arduino
  Serial.begin(9600);
  //Give status message
  Serial.println("IR Remote Demonstration");
  Serial.println("Starting Sensor");
  //start the sensor
  irrecv.enableIRIn();
  //print ready message
  Serial.println("Listening");
}

//runs many times
void loop() {
  //if found new results, print them
  if (irrecv.decode(&results)) {
    //print results using helper code to find the key press
    Serial.println(getString(results.value));
    // Receive the next value
    irrecv.resume();
  }
  //wait x milliseconds for data reliability
  delay(100);
}

//helper method to decode keypress from read infrared code
String getString(long code) {
  //switch statement will return the key press based on what the input was
  switch (code) 
  {
    //if the code was 0xFFA250, return 1 because key 1 was pressed
    case 0xFFA25D:      return  "1";
    //etc
    case 0xFF629D:      return  "2";
    case 0xFFE21D:      return  "3";
    case 0xFF22DD:      return  "4";
    case 0xFF02FD:      return  "5"; 
    case 0xFFC23D:      return  "6";
    case 0xFFE01F:      return  "7"; 
    case 0xFFA857:      return  "8";
    case 0xFF906F:      return  "9";
    case 0xFF9867:      return  "0";
    case 0xFF6897:      return  "*";
    case 0xFFB04F:      return  "#";
    case 0xFF18E7:      return  "Up";
    case 0xFF10EF:      return  "LEFT";
    case 0xFF38C7:      return  "OK";
    case 0xFF5AA5:      return  "RIGHT";
    case 0xFF4AB5:      return  "DOWN";
    //there is a special code if any button is repeated
    case 0xFFFFFFFF:    return  "Repeated";
    //this will return if no other button is found
    default:     return" other button";
  }

}
