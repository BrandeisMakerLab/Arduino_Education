/*Tactor Rig designed to convert ultrasonic distance sensor to tactile output on
a variety of modes. The modes are on/off, time, and encode.
Reads distance from an ultrasonic sensor Jacob Smith 2020/02/24*/

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <TactorRig.h>

//Creates a new TactorRig object
TactorRig::TactorRig() {
}

//Initializes the class, can't always be done at same time as constructor
void TactorRig::begin() {
	
	//sets the default tactor port
	this->tactorPort=2;
	//set pin to output
	pinMode(tactorPort, OUTPUT);
	//starts serial connection for printing output
	//doesn't wait in case this isn't used
	Serial.begin(9600);
	//start distance sensor
	distancesensor.begin(10, 11);
}

//vibrates the tactor in on off mode
void TactorRig::vibrateOnOff(){
  //gets the distance from the ultrasonic sensor
  double distance = distancesensor.getDistance();
  //print the mode
  Serial.print("ON OFF MODE:\t");
  //display distance to screen
  Serial.println(distance);
  //vibrates if distance is within range
  if (distance < 80 && distance>15) {
    digitalWrite(tactorPort, HIGH);   
  //otherwise turns fibrator off and waits x milliseconds
  } else {                  
    digitalWrite(tactorPort, LOW);    
  }
  delay(500);
}

//vibrates the tactor in encode mode
void TactorRig::vibrateEncode(){
  //gets the distance from the ultrasonic sensor
  double distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //if the distance is within range, invoke helper method
  if (distance < 200) {
    //encode distance for calibration
    pulseXTimes(distance / 10);
    //wait x seconds
    delay(2000);
  }
}


//vibrates the tactor in time mode
void TactorRig::vibrateTime(){
  //gets the distance from the ultrasonic sensor
  double distance = distancesensor.getDistance();
  //display distance to screen
  Serial.println(distance);
  //if distance is withing range, pulse depending on range
  if (distance < 80 && distance>15) {
    // turn the port on
    digitalWrite(tactorPort, HIGH);   
    //wait for x milliseconds
    delay(distance*10);
    digitalWrite(tactorPort, LOW);
     delay(distance*10); 
  }  
}

//pulses the provided number of times
void TactorRig::pulseXTimes(int numTimes) {
  //loops through number of times
  for (int i = 0; i < numTimes; i++) {
    pulse(200);
  }
}

//pulses for the specified period of time
void TactorRig::pulse(int pulseTime){
  digitalWrite(tactorPort, HIGH);
  delay(pulseTime);
  digitalWrite(tactorPort, LOW);
  delay(pulseTime);
}

