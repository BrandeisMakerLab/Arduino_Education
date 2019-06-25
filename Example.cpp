/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019*/

//this should work on all boards, so there is no preprocessor directive here

//include all of the classes necessary to make this one work
#include <Arduino.h>
#include <Example.h>

//Example constructor
Example::Example(){
}

//gives an array to the Example class and prints the length
void Example::begin (int pins[]) {
	if(!Serial){
		Serial.begin(9600);
	}
	numPins=sizeof(pins)/sizeof(pins[0]);
	this->pins = pins;
	Serial.print("Number of Pins:");
	Serial.println(numPins);
	
}

//prints all the pins in the array to prove it was stored in memory
void Example::printPins(){
	for(int i=0;i<numPins;i++){
		Serial.println(*(pins+i));
	}
	/*int* thresholds;
	return *(regions + i);*/
}