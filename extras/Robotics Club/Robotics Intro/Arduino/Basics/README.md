# Basics  

<p align="center">
  <img src=https://i.pinimg.com/originals/fc/3c/8f/fc3c8fca279aeded8050786c715c39bd.jpg width="350"/>
</p>  

"Basics" guides will be performed on the *Arduino Uno Rev3*. Other boards and eventually shields will be discussed, but they are not required for this segment.  
  
After finishing all the examples, you may want to get started on your own code. The best way to do so is by first creating your own sketch, and then checking these websites out:
* https://www.arduino.cc/reference/en/: Test out all the syntax of the Arduino language if you don't know what they do. You may find some methods / variables more useful than others in your project.
* https://www.arduino.cc/en/Reference/Libraries: Each library gives you functionality for specific hardware. Whichever one you want to use, you can click on for more examples and pin structures on how to use.

## Pinout
The image above is a great markdown of the Uno's structure. If your board is a knock-off Uno (such as Geekcreit)The small black squares are called *pins*, and you are able to insert wires into them. Some pins may be hard to read, so zoom in as you see fit.  

## Important Features of the Uno
A lot of these features may also appear on other boards, as they are __standard to electronics and how they work.__  
**GND:** When a circuit is looked at locally, ground is simply the one net someone picked to call 0V so that all other voltages are understood to be relative to it. GND is a pin that can be referred to as negative voltage to cancel out the positive voltage. This is why we always need a GND when we have positive voltage going through our circuit.  
**VIN:** Your "voltage input." This is called a 9V also on some other Arduino knockoffs, but recommended voltage is 7V-12V. VIN is simply a power pin to supply voltage through. If you are using any board other than an UNO, see https://www.arduino.cc/en/Main/Products?from=Main.Hardware for the recommended voltage (because it's different for each one. If you click on a board they should have their tech specs in the next page.  
**Microcontroller:** Sometimes, a microcontroller is confused for the whole board. In fact, it's a central processing unit (CPU) that is inexpensive, usually has a dedicated/designated task to run one program, and is embedded into the board. For the sake of what we're doing, this and the processor will be the ones that *remember* (memory) your programs and execute the logic behind it.
<p align="center">
  <img src=https://ktechnics.com/wp-content/uploads/2015/12/atmega328p-pu.png width="250"/>
</p>  
**Digital vs. Analog:** You can think of analog as a smooth, continuous signal that distributes voltage. There is an infinite range of voltages within a lower bound, a, and an upper bound, b. However, digital signals have a finite set of possible values (it could be either 5V or 0V). The best way to understand this is that an LED with digital can only be programmed ON or OFF (because you'll only have two digital values you can use). However, analog allows you to dim lights, increase brightness, or raise intensity because of the infinite range of voltage you can use.
<p align="center">
  <text>Analog</text>
  <img src=https://cdn.sparkfun.com/assets/3/7/6/6/0/51c48875ce395f745a000000.png width="250"/>
</p>
<p align="center">
  <text>Digital</text>
  <img src=https://cdn.sparkfun.com/assets/c/8/5/b/e/51c495ebce395f1b5a000000.png width="250"/>
</p>
**PWM:** The PWM pins are denoted by the tilde (~) markings and also the red check marks on the right. PWM means pulse-width modulation. todo  

## IDE Concepts 
Arduino is a set of C/C++ functions that can be called on your code, which is passed onto its own compiler. Sketches are *.ino* files, and for those who become advanced, you may eventually have to write your own libraries in *.h* files.  
**What are Libraries?**  
In short, libraries provide extra functionality to your code. They are written in C and C++, and you are able to write your own libraries. There should be a folder contained in your IDE that has a lot of open source library examples. You can import a library at the top of your IDE by going to *Sketch --> Import Library*. Finally, you can instantiate objects (i.e. **Servo** motor1;) and use library methods (i.e. motor1.write(200)). These will become a useful tool early on as you create your own sketches.   
  
**Setting Up Arduino COM ports and Boards**  
This step is important, otherwise you won't even be able to run your program. When you want to upload a program to your board, your computer will have to recognize the communication between the two via a port a board type. In *Tools* you should be able to change your board type any time you want. For our sake, change it to *Arduino/Genuino Uno*. Note that when you use other boards you will also be prompted for a processor type. This is because there may be multiple versions of a specific board.  
  
Once you plug in your board via USB to your computer, *Ports* will no longer be greyed out. This is because a communication has been established. Each board should have at least one serial port (usually by USB, but if there isn't one, you'll have to connect through digital pins 0 and 1 (RX and TX respectively). Note that some boards have ON/OFF switches. If it happens to be OFF, then you will not be able to see the port that it's on.  
  
  Lastly, you should be able to search *Device Manager* in your computer and find where it says *Ports (COM & LPT)*. You will be able to confirm what COM your board is on through there.  
  
**The setup() and loop()**  
An Arduino program can fully function if it has a setup and loop method. Arduino has a built in main method, so some C++ functionalities are abstracted away from the user. This makes it a lot easier to start coding.  
  
**Accessing Example Code Provided by Arduino**  
We have provided some examples in this directory, but it is important to understand that Arduino is all open-source, and provides a lot of tutorials online as well as in the IDE.
  1. Open your Arduino IDE.
  2. Go to *File --> Examples*. You should see *Basics*, so click on any of those examples to try them out.
  3. Follow their comments and directions. **In *Basics*, there is no assemblage of electronics required. All you need to do is connect an Arduino UNO to your computer.**
  4. As always, if you have any questions or problems, google them. There will most likely be someone who experienced the same thing.

## Hardware / Electronics Basics  
LED  
Servo Motor  
DC Motor  
Ultrasonic Sensor  

