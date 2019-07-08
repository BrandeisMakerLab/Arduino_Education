/*Display Class for use in earthmake lcd
 https://github.com/earthmake/arLCD/issues/2
 Created from example program and turned into class by Jacob Smith 2019/07/07*/

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <Display.h>

//Creates a new Display object
Display::Display() {
}

//Initializes the class, can't always be done at same time as constructor
void Display::begin(int min, int max) {
    //the lowest number that can be Displayed
    this->min = min;
    //the highest number that can be Displayed
    this->max = max;
    
     //starts up the Display and clears it
    lcd.begin( EZM_BAUD_RATE );
    lcd.cls( WHITE );
    //Displays an alaog meter
    lcd.analogMeter( 1, 50, 30, 200, 200, 1, 0, min, max, 1, 1, 0);
}

//Display a number and message to the screen
void Display::showMeter(char* message, int number) {
    //Display the message
    lcd.string(1, message);
    //Display the number on the gauge
    lcd.wvalue(1, number);

}
