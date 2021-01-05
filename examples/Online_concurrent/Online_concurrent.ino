/*
  Shows how to run an led on and off without stopping execution of other things
  Jacob Smith for Brandeis Automation Lab 10/16/20
*/

//time since light was turned off, benchmark time
long lightOneTime;

//runs once
void setup()
{
  //sets the pin to output instead of input because it's a light
  pinMode(13, OUTPUT);
  //start the benchmark time at current system time
  lightOneTime=millis();
  //start connection to computer
  Serial.begin(9600);
}

//runs many times
void loop()
{ 
  //print out system time, tab, and benchmark time
  Serial.print(millis());
  Serial.print("\t");
  Serial.println(lightOneTime);
 
  //if bechmakr time is greater than interval
  if (millis()-lightOneTime >500){
    //reset the time
  	lightOneTime=millis();
    //also flip light
    //!digitalRead(13) means set light to opposite of what it was
    digitalWrite(13,!digitalRead(13));
  }
}
