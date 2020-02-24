/*Tactor Rig designed to convert ultrasonic distance sensor to tactile output on
a variety of modes. The modes are on/off, time, and encode.
Reads distance from an ultrasonic sensor Jacob Smith 2020/02/24*/

//sets up the TactorRig Header file
#ifndef TactorRig_h
#define TactorRig_h

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <TactorRig.h>
#include <Arduino.h>
#include <DistanceSensor.h>


class TactorRig{
  private:
    //a distance sensor object to get the distance
	DistanceSensor distancesensor;
	//the digital port the tactor is plugged into on Arduino
	int tactorPort;
	
	//pulses the provided number of times
	void pulseXTimes(int numTimes);
	
	//pulses for the specified period of time
	void pulse(int pulseTime);
		
  public:
    //Creates a new TactorRig object
    TactorRig();
    //Initializes the class, can't always be done at same time as constructor
    void begin();
	//vibrates the tactor in on off mode
	void vibrateOnOff();
	//vibrates the tactor in encode mode
	void vibrateEncode();
	//vibrates the tactor in Time mode
	void vibrateTime();
	
};
#endif
