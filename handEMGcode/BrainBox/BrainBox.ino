/*

EMG SENSOR

  Use the "serial monitor" window to read EMG sensor.
  
  The BrainBox is an easy-to-use EMG that outputs
  a voltage that's proportional to your muscle activity.
  
  This script will use the Arduino's serial port
  to send data back to your main computer. 
  
Hardware connections:

  Be careful when installing the EMG wires from the BrainBox into the Arduino.
  
  Connect the red wire from the BrainBox to 5 Volts (5V) on the Arduino.
  Connect the white wire from the BrainBox to ANALOG pin 0 on the Arduino.
  Connect the black wire to ground (GND) on the Arduino.

This sketch was written by Professor Grace O'Connell and modifyied from Ardu. Copyright, 2016.

*/

#include <Servo.h>  // servo library

Servo servo1;  // servo control object
boolean lightSwitch = true;
int startingPosition = 0;

// We'll use analog input 0 to measure the temperature sensor's
// signal pin.

const int EMG = 0;


void setup()
{
  // In this sketch, we'll use the Arduino's serial port
  // to send text back to the main computer. For both sides to
  // communicate properly, they need to be set to the same speed.
  // We use the Serial.begin() function to initialize the port
  // and set the communications speed.
  
  // The speed is measured in bits per second, also known as
  // "baud rate". 9600 is a very commonly used baud rate,
  // and will transfer about 10 characters per second.
  servo1.attach(9);
  Serial.begin(9600);
}


void loop()
{

  float voltage;
  voltage = getVoltage(EMG);
  
  
//  int position;
//  // Read user signal thru bluetooth
//  // Set switch value depending on signal
//  lightSwitch = true;

  //  // Change position at full speed:
  //  servo1.write(180);   // Tell servo to go to 180 degrees
  //  delay(1000);         // Pause to get it time to move
//  servo1.write(startingPosition);     // Tell servo to go to 0 degrees
//  delay(1000);         // Pause to get it time to move
 
  // To open the serial monitor window, upload your code,
  // then click the "magnifying glass" button at the right edge
  // of the Arduino IDE toolbar. The serial monitor window
  // will open.

  // (NOTE: remember we said that the communication speed
  // must be the same on both sides. Ensure that the baud rate
  // control at the bottom of the window is set to 9600. If it
  // isn't, change it to 9600.)
  
  // Also note that every time you upload a new sketch to the
  // Arduino, the serial monitor window will close. It does this
  // because the serial port is also used to upload code!
  // When the upload is complete, you can re-open the serial
  // monitor window.
  
  // To send data from the Arduino to the serial monitor window,
  // we use the Serial.print() function. 

  Serial.println(voltage);

//  if(voltage > 500){
//    delay(1000); 
//    servo1.write(90); 
//    delay(1000);
//    startingPosition = 90;
//  }
//  else{
//    delay(1000); 
//    servo1.write(180);
//    delay(1000); 
//    startingPosition = 180;
//  }

  // Note that the above statement uses "println", which will insert 
  // a "carriage return" character at the end of whatever it prints, 
  // moving down to the NEXT line.
  delay(10); // repeat once per second (change as you wish!)
}


float getVoltage(int pin)
{
  // This function has one input parameter, the analog pin number
  // to read. You might notice that this function does not have
  // "void" in front of it; this is because it returns a floating-
  // point value, which is the true voltage on that pin (0 to 5V).
  
  // You can write your own functions that take in parameters
  // and return values (This is similar to Matlab functions). Here's how:
  
    // To take in parameters, put their type and name in the
    // parenthesis after the function name (see above). You can
    // have multiple parameters, separated with commas.
    
    // To return a value, put the type BEFORE the function name
    // (see "float", above), and use a return() statement in your code
    // to actually return the value (see below).
  
    // If you don't need to get any parameters, you can just put
    // "()" after the function name.
  
    // If you don't need to return a value, just write "void" before
    // the function name.

  // Here's the return statement for this function. We're doing
  // all the math we need to do within this statement:
  return (analogRead(pin));
  // subtract ~500 for spiker box. Note this value is based on calibration
  // studies with a single spiker box - your box may have a different "zero" point.
  
}
