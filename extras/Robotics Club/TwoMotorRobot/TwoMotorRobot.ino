#include <Wire.h>
#include <Bricktronics.h>

//Bricktronics Example: TwomotorRobot
//http://www.wayneandlayne.com/bricktronics

Bricktronics brick = Bricktronics();
Motor m = Motor(&brick, 1);
Motor m2 = Motor(&brick, 2);
int power=150;
int time=1000;
void setup()
{
    Serial.begin(115200);
    Serial.println("Hello world.");
    brick.begin();
    m.begin();
    m2.begin();
}

void loop() 
{
    m.set_speed(power);
    m2.set_speed(power);
    delay(time);    
    m.set_speed(-power);
    m2.set_speed(-power);
    delay(time);   
}
