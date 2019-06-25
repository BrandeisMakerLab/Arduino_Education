/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019
Sources:
https://forum.arduino.cc/index.php?topic=508126.0
https://blog.feabhas.com/2013/11/shock-horror-i-learned-something-about-arrays-in-c/
*/
#ifndef ArduinoEducation_h
#define ArduinoEducation_h

//this should work on all boards, so there is no preprocessor directive here

#include <Arduino.h>
#include<ArduinoEducation.h>
//create macro to get length of array
#define ARRAY_SIZE(arr)((sizeof(arr))/sizeof(arr[0]))

class ArduinoEducation{
	
	private:
		//an array containing pin numbers for an ArduinoEducation
		int* pins;
		//the length of the array
		int numPins;
	public:
		//creates a new ArduinoEducation object
		ArduinoEducation();
		//gives an array to the ArduinoEducation class and prints the length
		void ArduinoEducation::begin (int pins [], int numPins);

		//prints all the pins in the array to prove it was stored in memory
		void ArduinoEducation::printPins();
	
};

#endif