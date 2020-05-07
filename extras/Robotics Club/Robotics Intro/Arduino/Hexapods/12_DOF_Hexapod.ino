/*                                                __    __     __________   _______        __                              _________
 *         /\        /\                  _       |  |  / /    |   _______| |   __  \      |  |                            |   ___   \
 *        /  \      /  \                / \      |  | / /     |  |         |  |  |  \     |  |                    _       |  |   \   \
 *       /    \    /    \              /   \     |  |/ /      |  |         |  |  |  /     |  |                   / \      |  |    \  |
 *      /  /\  \  /  /\  \            /  _  \    |     \      |  |_______  |  |__| /      |  |                  /   \     |  |    /  /
 *     /  /  \  \/  /  \  \          /  / \  \   |  |\  \     |   _______| |       \      |  |                 /  _  \    |  |___/  /
 *    /  /    \    /    \  \        /  /___\  \  |  | \  \    |  |         |   ___  \     |  |                /  / \  \   |  |___  \
 *   /  /      \  /      \  \      /  /_____\  \ |  |  \  \   |  |         |  |   \  \    |  |               /  /___\  \  |  |    \ \
 *  /  /        \/        \  \    /  /       \__\|__|   \  \  |  |       __|  |    \  \   |  |              /  /_____\  \ |  |     \ \
 * /__/                    \  \  /  /                    \  \ |  |______/ /|  |     \  \  |  |             /  /       \__\|  |     / |
 *                          \__\/__/                      \__\|__________/ |__|      \  \ |  |__________  /  /            |  |____/  /
 *                                                                                    \__\|_____________|/__/             |_________/
 *
 * DESCRIPTION: DAGU 12 DOF Hexapod sample code written by Russell Cameron. Original code can be found here:
 * 
 *              https://sites.google.com/site/daguproducts/home/download-page
 *              
 * Contributers: Tim Hebert, Jonas Tjahjadi
 * 
 * ADAPTATION: This code has been adapted to create a keyboard interface for a 12 DOF (or 12 servo) hexapod.
 *             The IR Remote actions have been removed. Additionally, more functionalities have been added to mess around with the hexapod.
 *
 * OLD, UNUSED LIBRARIES: <IRremote.h> and <IRremoteInt.h>, which can be found here:
 * 
 *                        http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html (credentials to Ken Shirriff)
 */
 
#include <Servo.h>                                         // Standard Arduino servo libarary

int svc[12]={                                              // servo center positions (typically 1500uS)
  1500,1550,1550,1450,                                     // D29 knee1, D46 Hip1, D47 knee2, D48 Hip2
  1500,1400,1500,1550,                                     // D49 knee3, D50 Hip3, D51 knee4, D24 Hip4
  1500,1500,1500,1400                                      // D25 knee5, D26 Hip5, D27 knee6, D28 Hip6
};

Servo sv[12];                                              // Yes! servos can be an array

int angle;                                                 // determines the direction/angle (0°-360°) that the robot will walk in 
int rotate;                                                // rotate mode: -1 = anticlockwise, +1 = clockwise, 0 = no rotation
int Speed;                                                 // walking speed: -15 to +15 
int Stride;                                                // size of step: exceeding 400 may cause the legs to hit each other

int incomingByte;                                          //to read user input, each key on keyboard is an integer value
float multiplier;                                          //to allow user to adjust speed in menu display using a speed multiplier



void setup()
{
  Serial.begin(9600);

  //12 SERVO SET UP
  sv[0].attach(29,800,2200);                               // knee 1 
  sv[1].attach(46,800,2200);                               // Hip  1
  sv[2].attach(47,800,2200);                               // knee 2
  sv[3].attach(48,800,2200);                               // Hip  2
  sv[4].attach(49,800,2200);                               // knee 3
  sv[5].attach(50,800,2200);                               // Hip  3
  sv[6].attach(51,800,2200);                               // knee 4
  sv[7].attach(24,800,2200);                               // Hip  4
  sv[8].attach(25,800,2200);                               // knee 5
  sv[9].attach(26,800,2200);                               // Hip  5
  sv[10].attach(27,800,2200);                              // knee 6
  sv[11].attach(28,800,2200);                              // Hip  6
  
  for(int i=0;i<12;i++)
  {
    sv[i].writeMicroseconds(svc[i]);                       // initialize servos
  }
  
  Serial.println("Start");
}

void loop()
{ 
    if(Serial.available() > 0) 
    {  
    incomingByte = Serial.read();

    if(incomingByte == 96) 
    {
      Serial.println("Menu Displayed:\n");
      multiplier = 0;
      while(multiplier == 0)
      {
        if(Serial.available() > 0) 
        {
          multiplier = ((int)Serial.read() - 48);
          Serial.println(multiplier);
//        plusOrMinus = Serial.read();
        }
        
      }
      String result = "Multiplier set to %f", multiplier;
      Serial.println(result);
    }

    //SUPPORTED ACTIONS

    if(incomingByte == 32)                              // STOP (SPACE)
    {
      Serial.println("stopped");
      Speed=0;
      angle=0;
      rotate=0;
    }
    
    if(incomingByte == 119)                              // FORWARD  (W)
    {
      Serial.println("moving forward");
      Speed=10;
      rotate=0;
      angle=0;
    }
    
    if(incomingByte == 115)                             // REVERSE  (S)
    {
      Serial.println("reversing");
      Speed=-10;
      rotate=0;
      angle=0;
    }

    if(incomingByte == 97)                             // STRAFE LEFT (A)
    {
      Serial.println("SKRRRRSKRR Left.");
      Speed=-10;
      rotate=0;
      angle=0;
    }

    if(incomingByte == 100)                             // STRAFE RIGHT (D)
    {
      Serial.println("SKRRRRRRRRRR Right.");
      Speed=-10;
      rotate=0;
      angle=0;
    }
    
    if(incomingByte == 101)                               // ROTATE CLOCKWISE (E)
    {
      Serial.println("Rotate clockwise");
      Speed=10;
      rotate=1;
      angle=0;
    }
    
    if(incomingByte == 113)                                          // ROTATE COUNTER CLOCKWISE  (Q)
    {
      Serial.println("Rotate counterclockwise");
      Speed=10;
      rotate=-1;
      angle=0;
    }
    /*
    if(IRC==16)                                            // 45 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=45;
    }
    
    if(IRC==3088)                                          // 90 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=90;
    }
    
    if(IRC==1552)                                          // 135 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=135;
    }
    
    if(IRC==272)                                           // 225 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=225;
    }
    
    if(IRC==2576)                                          // 270 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=270;
    }
    
    if(IRC==1040)                                          // 315 DEGREES    
    {
      Speed=10;
      rotate=0;
      angle=315;
    }
    //irrecv.resume();                                       // receive the next value
    */
  }
  
  if (angle<0) angle+=360;                                 // keep travel angle within 0°-360°
  if (angle>359) angle-=360;                               // keep travel angle within 0°-360°
  Speed = Speed * (multiplier/10);
  multiplier = 10;                                         //set speed = speed * 1
  Walk();                                                  // move legs to generate walking gait
  delay(15);
}


void Walk()                                                // all legs move in a circular motion
{
  if(Speed==0)                                             // return all legs to default position when stopped
  {
    Stride-=25;                                            // as Stride aproaches 0, all servos return to center position
    if(Stride<0) Stride=0;                                 // do not allow negative values, this would reverse movements
  }
  else                                                     // this only affects the robot if it was stopped
  {
    Stride+=25;                                            // slowly increase Stride value so that servos start up smoothly
    if(Stride>450) Stride=450;                             // maximum value reached, prevents legs from colliding.
  }
  
  float A;                                                 // temporary value for angle calculations
  double Xa,Knee,Hip;                                      // results of trigometric functions
  static int Step;                                         // position of legs in circular motion from 0° to 360°                               
  
  for(int i=0;i<6;i+=2)                                    // calculate positions for odd numbered legs 1,3,5
  {
    A=float(60*i+angle);                                   // angle of leg on the body + angle of travel
    if(A>359) A-=360;                                      // keep value within 0°-360°
   
    A=A*PI/180;                                            // convert degrees to radians for SIN function
    
    Xa=Stride*rotate;                                      // Xa value for rotation
    if(rotate==0)                                          // hip movement affected by walking angle
    {
      Xa=sin(A)*-Stride;                                   // Xa hip position multiplier for walking at an angle
    }
        
    A=float(Step);                                         // angle of leg
    A=A*PI/180;                                            // convert degrees to radians for SIN function
    Knee=sin(A)*Stride;
    Hip=cos(A)*Xa;
    
    sv[i*2].writeMicroseconds(svc[i*2]+int(Knee));         // update knee  servos 1,3,5
    sv[i*2+1].writeMicroseconds(svc[i*2+1]+int(Hip));      // update hip servos 1,3,5
  }
  
  for(int i=1;i<6;i+=2)                                    // calculate positions for even numbered legs 2,4,6
  {
    A=float(60*i+angle);                                   // angle of leg on the body + angle of travel
    if(A>359) A-=360;                                      // keep value within 0°-360°
   
    A=A*PI/180;                                            // convert degrees to radians for SIN function
    Xa=Stride*rotate;                                      // Xa value for rotation
    if(rotate==0)                                          // hip movement affected by walking angle
    {
      Xa=sin(A)*-Stride;                                   // Xa hip position multiplier for walking at an angle
    }
        
    A=float(Step+180);                                     // angle of leg
    if(A>359) A-=360;                                      // keep value within 0°-360°
    A=A*PI/180;                                            // convert degrees to radians for SIN function
    Knee=sin(A)*Stride;
    Hip=cos(A)*Xa;
    
    sv[i*2].writeMicroseconds(svc[i*2]+int(Knee));         // update knee  servos 2,4,6
    sv[i*2+1].writeMicroseconds(svc[i*2+1]+int(Hip));      // update hip servos 2,4,6
  }
  
  Step+=Speed;                                             // cycle through circular motion of gait
  if (Step>359) Step-=360;                                 // keep value within 0°-360°
  if (Step<0) Step+=360;                                   // keep value within 0°-360°
}
