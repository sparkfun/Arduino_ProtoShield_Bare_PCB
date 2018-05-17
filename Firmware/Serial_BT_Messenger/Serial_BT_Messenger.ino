/*
  Example Serial Bluetooth Messenger
  by: Ho Yun "Bobby" Chan
  SparkFun Electronics
  date: May 16, 2018
  license: Public domain

  This example sketch converts an RN-42 bluetooth module to
  communicate at 9600 bps (from 115200). Assuming that the
  two bluetooths are paired and configured to autoconnect,
  a message is sent with the push of a button. Any 
  received characters from the other bluetooth will display 
  on the serial monitor. 

  This sketch was written by SparkFun Electronics.
  This example is based on the Example Bluetooth Serial 
  Passthrough Sketch by Jim Lindblom.

  This code is completely free for any use.
  Visit https://learn.sparkfun.com/tutorials/using-the-bluesmirf
  for more information.
****************************************************************/

#include <SoftwareSerial.h>

const int SW2 = 2;  // pushbutton 1 pin
const int L1 =  13;    // LED pin for push button
const int L2 =  6;     // LED pin for received character

int button1State;  // variables to hold the pushbutton states

int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D10
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D11

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);// (Arduino SS_RX = pin 10, Arduino SS_TX = pin 11)

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(SW2, INPUT);
  // Set up the LED pin to be an output:
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  Serial.begin(9600);  // Begin the serial monitor at 9600bps

  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

void loop()
{
  button1State = digitalRead(SW2);

  //Send a character
  if (button1State == LOW) //if SW2 is pressed
  {
    // Send characters to bluetooth to transmit
    bluetooth.println("Hi!");
    digitalWrite(L1, HIGH);  // turn the LED on
  }
  else {
    digitalWrite(L1, LOW);  // turn the LED off
  }

  // If the bluetooth received any characters, print to the serial monitor
  if (bluetooth.available())
  {
    // Send any characters the bluetooth prints to the serial monitor
    Serial.print((char)bluetooth.read());
    digitalWrite(L2, HIGH);  // turn the LED on
  }
  else {
    digitalWrite(L2, LOW);  // turn the LED on
  }
  // and loop forever and ever!
}

