/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019
Sources:
https://forum.arduino.cc/index.php?topic=508126.0
https://blog.feabhas.com/2013/11/shock-horror-i-learned-something-about-arrays-in-c/
*/

//this should work on all boards, so there is no preprocessor directive here

//include all of the classes necessary to make this one work
#include <Arduino.h>
#include <Wire.h>
#include <ArduinoEducation.h>

//ArduinoEducation constructor
ArduinoEducation::ArduinoEducation(){
}

//gives an array to the ArduinoEducation class and prints the length
void ArduinoEducation::begin (int pins[], int numPins) {
	if(!Serial){
		//Serial.begin(9600);
		while(!Serial){}
	}
	//this->numPins=sizeof(pins)/sizeof(pins[0])+2;
	this->numPins=numPins;
	this->pins = pins;
	Serial.print("Number of Pins:");
	Serial.println(numPins);
	
}

//prints all the pins in the array to prove it was stored in memory
void ArduinoEducation::printPins(){
	for(int i=0;i<numPins;i++){
		//Serial.println(*(pins+i));
		Serial.println(pins[i]);
	}
	delay(5000);

}