/*Temperature Sensor for 37 sensor kit
 * https://www.instructables.com/id/Arduino-37-in-1-Sensors-Kit-Explained/
 * Curated Jacob Smith Brandeis University
*/

#include <OneWire.h>
 
// DS18S20 Temperature chip i/o
OneWire ds(10);  // on pin 10

  //For conversion of raw data to C
  int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;
 
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  double temp;
void setup(void) {
  // initialize inputs/outputs
  // start serial port
  Serial.begin(9600);
  Serial.println("Prints Temperature in Celsius");
}
 
void loop(void) {
 
  temp=getTemp();
  Serial.print("Temperature is\t");
  Serial.println(temp);
}

//returns temperature in Celsius
//will wait one second
double getTemp(){
    if ( !ds.search(addr)) {
      ds.reset_search();
      return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end
 
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
 
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad
 
  //Serial.print("P=");
  //Serial.print(present,HEX);
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  //Conversion of raw data to C
  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;  // test most sig bit
  if (SignBit) // negative
  {
    TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25
 
  Whole = Tc_100 / 100;  // separate off the whole and fractional portions
  Fract = Tc_100 % 100;
 
  //prepare to return answer
  double temp=Whole+Fract/100.0;
  //End conversion to C
  if(SignBit){
      temp*=-1;
  }
  return temp;
}
