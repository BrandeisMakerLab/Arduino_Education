/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019*/
#ifndef Example_h
#define Example_h

//this should work on all boards, so there is no preprocessor directive here

#include <Arduino.h>
#include<Example.h>

class Example{
	
	private:
		//an array containing pin numbers for an example
		int* pins;
		//the length of the array
		int numPins;
	public:
		//creates a new Example object
		Example();
		//Example constructor
		Example::Example();

		//gives an array to the Example class and prints the length
		void Example::begin (int pins []);

		//prints all the pins in the array to prove it was stored in memory
		void Example::printPins();
}
		
};

#endif