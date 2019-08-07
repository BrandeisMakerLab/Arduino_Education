//imports the library that must be used to run this program
#include <DHT.h>
#include <DHT_U.h>
#define BLUEPIN 4
#define REDPIN 3
//initializes the part so that the program knows what to expect to run
DHT dht(2,DHT22);
float initHumid;
void setup() {
  //initialize serial port (allows for commuication with arduino by clicking on the magnifying glass
  //on the top right corner of the window AFTER the program is uploaded
  Serial.begin(9600);
   // initialize digital pin LED_BUILTIN as an output.
  pinMode(BLUEPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  //starts the loop
  dht.begin();
  initHumid = dht.readHumidity();
  if (initHumid >= 50)
    pinMode(REDPIN, OUTPUT);

  else
    pinMode(BLUEPIN, OUTPUT);
}
void loop() {
  float humidity = dht.readHumidity();
  Serial.print("init");
  Serial.println(initHumid);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  
  delay(500);
  if(humidity>initHumid+.5){
    Serial.println("blue on");
    switchLight(BLUEPIN,REDPIN);
  }else{
    Serial.println("red on");
    switchLight(REDPIN,BLUEPIN);  
  }
}

void switchLight(int onPin, int offPin){
 digitalWrite(onPin, HIGH);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(offPin, LOW);   // turn the LED on (HIGH is the voltage level)
 
}
