// NOTE: To test this program, download the sketch and open it on Arduino. 
// Plug in your Arduino to your computer via USB. Go to Tools -> Board and pick the board you are using.
// Again, go to Tools -> Board and pick the right port (see main README if you're confused on this part).
// Click on the top right magnifying glass icon. This is your "Serial Monitor," and you can see the output here.

/* Outside of the setup and loop, we can write our own methods, include libraries, and declare global variables
 * which are just things that the whole code can see (more on these later). Usually, global variables are used to
 * declare pin numbers and instantiate new hardware we will be using, such as a Servo.
 */

/*
 * The setup is useful to initializing / creating things that you don't ever have to mess with again. For example, 
 * consider a servo motor again. We want to attach it to a specific pin, so we would attach it here and leave it be.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  /* Serial is used to communicate between the board and other devices (usually a computer)
   * begin starts it for the first time, establishing the bits per second as a parameter, which is 9600.
   * This is the rate at which data is being transmitted, and this is the most common one for communicating with the computer.
   */
  Serial.println("This is my setup! I will only say this once.");
}

// This is your method that runs forever until you shut down the program.
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I'm looping...");
  // you can pause your program in terms of milliseconds. I'll use 1000 here, to make it print the above statement every second.
  delay(1000);
}
