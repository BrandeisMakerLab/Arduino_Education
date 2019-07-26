//imports the library that must be used to run this program
#include <DHT.h>
#include <DHT_U.h>
#define BLUEPIN 4
#define REDPIN 3
//initializes the part so that the program knows what to expect to run
DHT dht(2, DHT22);
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
  pinMode(2, OUTPUT);
}
void loop() {
  float humidity = dht.readHumidity();
  Serial.print("init");
  Serial.println(initHumid);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  delay(500);
  if (humidity > 50) { // the setup function runs once when you press reset or power the board
digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50); 

  } else {
    digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
    delay(50);


  }

}


/*void flash(){
  loop;
  loop;
  loop;
  loop;
  loop;
  loop;
  loop;
  }


  // the loop function runs over and over again forever
  void loop()
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(50);                     // wait for a second*/
