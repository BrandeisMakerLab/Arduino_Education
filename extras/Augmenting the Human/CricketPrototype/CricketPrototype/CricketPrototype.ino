/* Cricket Protoype Example Program
 *  Made by Jacob Smith for Brandeis Augmenting the Human Initiative
 *  uses https://www.journals.uchicago.edu/doi/pdfplus/10.1086/277503 
 *  to convert temperature to number of chirps, like a cricket
 *  components: buzzer and temperature sensor
 */
//include background library for sensor
#include <Adafruit_BME280.h>  // include adafruit library for BME280 sensor
//the library object 
Adafruit_BME280 bme280;

//include the necessary background library
#include <TonePlayer.h>
//Use the Tone player background code, using the name tone1 to refer to it by
TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);
//the temperature in degreees celsius
double tempC;
//the temperatuer in degrees fahrenheit 
double tempF;

//runs once for setup
void setup()
{
  //set the buzzer pin to be outout
  pinMode (9, OUTPUT);  // output pin is fixed (OC1A)
  ///start usb connection to Arduino
  Serial.begin(9600);
  //wait for connectino to start
  while(!Serial){} 
  //print demonstration prompt
  Serial.println("\n\nCricket Prototype Demonstration");
  Serial.println("Chirps a number of times based on the temperature\n");

  //start the snesor at specified address
  if (!bme280.begin(0x76))
  {  
    //if the sensor doesn't connect, print warning
    Serial.println("Could not find a valid Temperature sensor, check wiring and reupload");
    //wait forever so user uploads
    while (1);
  }
 
}

//runs many times
void loop()
{
  //get the temperature in degrees C
  tempC=bme280.readTemperature();
  //convert to degrees F
  tempF=9.0/5.0*tempC+32.0;
  //print the temperature
  Serial.print("Temperature (°F) = ");
  Serial.print(tempF);
  Serial.print("\tChirps = ");
  Serial.println(chirpFromTemp(tempF));
      
  //wait x milliseconds before repeating
  //so user can tell when a sequence of chirps stops
  delay(3000); 
  
}

//converts temperature in degrees fahrenheit to number of cricket chirps
//input temp in fahrenheit, chirps that number of times, output number of times chirpes
int chirpFromTemp(double temp){
  //calculate number of chirps according to formula aboce
  double numChirps=(temp-50)*4+40;
  //chirp a third as much so they are easier to count
  numChirps=numChirps/3;;
  //iterate through a loop to chirp that many times
  for (int i=0;i<numChirps-1;i++){
    //play a note on buzzer
    tone1.tone (500);
    //wait x milliseconds for note to play
    delay (200);
    //stop note on buzzer
    tone1.noTone ();
    delay(200);
  }
  //return the number of Chirps so it can be printed to the screen
  return numChirps;
}
