/*Momentary Push Button

  Use momentary pushbuttons for digital input

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This example is based on the push button
  example in the SparkFun Inventor's Kit v3.3

  This code is completely free for any use.
  Visit https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v33/experiment-5-push-buttons
  for more information.
  Visit http://www.arduino.cc to learn about the Arduino.

  Version 2.0 6/2012 MDG
  Version 2.1 9/2014 BCH
****************************************************************/

const int SW2 = 2;  // pushbutton 1 pin
const int L1 =  13;    // LED pin
const int L2 =  6;     // LED pin

int button1State;  // variables to hold the pushbutton states

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(SW2, INPUT);
  // Set up the LED pin to be an output:
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
}

void loop()
{
  button1State = digitalRead(SW2);

  // if SW2 is pressed
  if (button1State == LOW) {
    digitalWrite(L1, HIGH);  // turn the LED on
    digitalWrite(L2, HIGH);  // turn the LED on
  }
  else {
    digitalWrite(L1, LOW);  // turn the LED off
    digitalWrite(L2, LOW);  // turn the LED off
  }
}

