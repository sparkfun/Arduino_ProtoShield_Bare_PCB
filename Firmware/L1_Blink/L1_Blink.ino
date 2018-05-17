/*BLINKING AN LED

  Turn an LED on for one second, off for one second,
  and repeat forever.

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This example is based on the blinking an LED
  example in the SparkFun Inventor's Kit v3.3.

  This code is completely free for any use.
  Visit https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v33/experiment-1-blinking-an-led
  for more information.
  Visit http://www.arduino.cc to learn about the Arduino.

  Version 2.0 6/2012 MDG
******************************************************************************/


// The LED is connected to digital pin 13
// Change the pin number depending on 
// what L1 is connected to.
const int L1 = 13;

void setup()
{
  pinMode(L1, OUTPUT);  //Set L1 to output
}

void loop()
{
  digitalWrite(L1, HIGH);   // Turn on the LED
  delay(1000);                     // Wait for one second
  digitalWrite(L1, LOW);    // Turn off the LED
  delay(1000);                     // Wait for one second
}
