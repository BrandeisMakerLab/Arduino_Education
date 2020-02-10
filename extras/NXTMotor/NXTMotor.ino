// Bricktronics Example: MotorSingle
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Motor.
//
// This example starts the motor at an intermediate speed,
// then speeds it up to full speed, and does the same in reverse.
//
//use a power souce
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
 
 
// Include the Bricktronics Motor library and helper libraries
// Helper libraries can be downloaded from:
// https://www.pjrc.com/teensy/td_libs_Encoder.html
// https://github.com/br3ttb/Arduino-PID-Library/
//  Be sure to rename unzipped folder PID_v1
//need bricktronics motor and shield
#include <Encoder.h>
#include <PID_v1.h>
#include <BricktronicsMotor.h>
 
 
// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.
 
// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// You also need to install the Adafruit MCP23017 library:
//  https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
// Select the motor port (MOTOR_1 or MOTOR_2) in the constructor below.
//
// Config 1 - arduino:avr:uno
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
BricktronicsMotor m(BricktronicsShield::MOTOR_1);
 
void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);
  BricktronicsShield::begin();
  // Config end
 
  // Initialize the motor connections
  m.begin();
}
 
void loop() 
{
  Serial.println("Going forward.");
  m.setFixedDrive(75);
  delay(1000);
 
  m.setFixedDrive(255);
  delay(1000);
 
  Serial.println("Going in reverse.");
  m.setFixedDrive(-75);
  delay(1000);
 
  m.setFixedDrive(-255);
  delay(1000);
}
