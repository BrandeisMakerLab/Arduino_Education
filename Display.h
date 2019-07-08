/*Display Class for use in earthmake lcd
 https://github.com/earthmake/arLCD/issues/2
 Created from example program and turned into class by Jacob Smith 2019/07/07*/

//sets up the analogMeter Header file
#ifndef Display_h
#define Display_h

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <Display.h>
#include <ezLCDLib.h>

class Display{
  private:
    //the base lcd object to interface with hardware
    ezLCD3 lcd;
    //the lowest number that can be Displayed
    int min;
    //the highest number that can be Displayed
    int max;
  public:
    //Creates a new analogMeter object
    Display();
    //Initializes the class, can't always be done at same time as constructor
    void begin(int min, int max);
    //Display a number and message to the screen
    void showMeter(char* message, int number);
};
#endif
