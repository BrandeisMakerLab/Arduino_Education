/*Written by Jacob Smith for Brandeis Robotics Club  March 8 2018
 Drives the motor at set powers si it moves in a pattern
 */
//includes the header file of the library
#include <MotorsGeneral.h>

//creates a global reference to a Drive object
MotorsGeneral robot;

//occurs before the program enters its main loop
//blank here because no setup is required
void setup() {}

//the main loop of the robot, runs forever
void loop() {
  //commands the robot to drive forward, numbers are left speed, right speed, and time
  //so this command is frive forward for half a second
  robot.setSpeeds(300,300,500);
  //drive backward
  robot.setSpeeds(-300,-300,500);
  //turn right
  robot.setSpeeds(300,-300,500);
  //turn left
  robot.setSpeeds(-300,300,500);
  //stop
  robot.setSpeeds(0,0,500);
}
