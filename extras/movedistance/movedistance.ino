#include <DriveShield.h>
#include <DistanceSensor.h>
//includes the header file of the library


//creates a global reference to a Drive object
DriveShield robot;

//name the distane sensor
DistanceSensor distancesensor;
int distance;
//variable to store the distance

void setup() {
  // put your setup code here, to run once:
    //start the distance sensor
  distancesensor.begin(2, 6);
  //start the usb connection to the computer
  Serial.begin(9600);
    //commands the robot to stop for 2 seconds
  robot.stopDrive(2000);

}

void loop() {
    //get the distance
    distance = 3;
 // distance=distancesensor.getDistance();
  //print the distance to the serial monitor
  Serial.println( analogRead(A0));
   int sensorValue = analogRead(A0);
  // put your main code here, to run repeatedly:
  if (sensorValue < 200 && sensorValue > 0) {
    robot.turnLeft(300);
  } else if (sensorValue < 600 && sensorValue >400) {
    robot.driveForward(500);
  }else if (sensorValue < 800 && sensorValue > 600) {
      robot.turnRight(300);
  } else if (sensorValue > 900) {
      robot.driveBackward(500);
  }
}
