/*Written by Jacob Smith for Brandeis Automation Lab 12/30/20
Shows how arrays can be used in Arduino
*/
//create list of pins numbers
//we don't have to specify thesie because we are making it all at once
int pins [] = {3,1,2,5,7,6,8};
//the setup method runs once
void setup() {
  //connect the arduino to the computer
  Serial.begin(9600);
  //wait for it to connect
  delay(1000);
  //print intro message
  Serial.println("Array Example Program");
  Serial.println("Position Value");
  //loop through every position in the list
  //the variable i will go from 0 to 6
  for (int i=0;i<7;i++){
    //print the position number and the number at that positio
  	Serial.print(i);
    Serial.print("\t");
    Serial.println(pins[i]);
  }
  
  //show that the value at a position can be changed
  Serial.println("Changing Value at Position 0");
  Serial.println("Before");
  Serial.println(pins[0]);
  pins[0]=5;
  Serial.println("After");
  Serial.println(pins[0]);
}
//Not Used Here
void loop() {}