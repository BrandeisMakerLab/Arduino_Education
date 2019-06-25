/*Written by Jacob Smith for Arduino Outreach Project
Shows how arrays can be used in Arduino Classes to allow the 
user to input an array without having to specify its size
June 24 2019*/

ArduinoEducation test;
void setup() {
  int pins={5,6,7};
  test.begin(pins);

}

void loop() {
  test.printPins();
}
