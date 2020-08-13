/*TRIG Group 7/30/20
 * Connects the Bn055 orinetion sensor to vibrotactrs/leds
 * for use in a balnce protoype
 * Got to skecth-->include library-->manage libraries
 *  and search BNO055, pick adafruit
 * Wiring
 * SCL-Analog 5
 * SDA-Analog 4
 * Gnd-Gnd
 * Vin-5V
 * https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/assembly
*/
//background lirbaries needed here
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//pin locations of tactors
int leftPin=2;
int rightPin=3;
int forPin=5;
int backPin=4;
//pin locations of leds correspondign to tactors
int leftPinLED=10;
int backPinLED=11;
int rightPinLED=8;
int forPinLED=9;

//runs once
void setup(void) 
{ 
  //set pins for tactos and leds to output
  pinMode(leftPin,OUTPUT);
  pinMode(rightPin,OUTPUT);
  pinMode(forPin,OUTPUT);
  pinMode(backPin,OUTPUT);
  
  pinMode(leftPinLED,OUTPUT);
  pinMode(rightPinLED,OUTPUT);
  pinMode(forPinLED,OUTPUT);
  pinMode(backPinLED,OUTPUT);
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000); 
  bno.setExtCrystalUse(true);

   //show that every tactor/led works
  //by cycling through all of them
  leftRight(true,false);
  delay(1000);
  leftRight(false,true);
  delay(1000);
  leftRight(false,false);
  frontBack(true,false);
  delay(1000);
  frontBack(false,true);
  frontBack(false,false);
  delay(1000);
}
 
void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");

   //get left right orientatino and set tactors/leds
  if(event.orientation.z<-50){
    leftRight(true,false);
  }else if (event.orientation.z>50){
    leftRight(false,true);
  }else{
    leftRight(false,false);
  }
   //get front back orientatino and set tactors/leds
   if(event.orientation.y<-50){
    frontBack(true,false);
  }else if (event.orientation.y>50){
    frontBack(false,true);
  }else{
    frontBack(false,false);
  }
  
  delay(100);
}

//sets the left and right tactors/leds to desired state
void leftRight(bool leftState,bool rightState){
  digitalWrite(leftPin,leftState);
  digitalWrite(leftPinLED,leftState); 
  digitalWrite(rightPin,rightState);
  digitalWrite(rightPinLED,rightState); 
}

//sets the forward and baclward tactors/leds to desired state
void frontBack(bool frontState,bool backState){
  digitalWrite(forPin,frontState);
  digitalWrite(forPinLED,frontState); 
  digitalWrite(backPin,backState);
  digitalWrite(backPinLED,backState); 
}
