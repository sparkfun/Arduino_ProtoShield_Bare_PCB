/* Fading LED

  Use for-loops to smoothly vary the brightness of an LED

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This example is based on the Fading LEDs example
  in the LilyPad Development Board Activity Guide.

  This code is completely free for any use.
  Visit https://learn.sparkfun.com/tutorials/lilypad-development-board-activity-guide/4-fading-leds
  for more information
  Visit http://www.arduino.cc to learn about the Arduino.

******************************************************************************/

// Create integer variable for the LED pin we'll be using:
const int L2 = 6;

// Create a new integer variable called brightness:
int brightness;

void setup()
{
  // Set the LED pins to be output:
  pinMode(L2, OUTPUT);
}

void loop()
{
  // The two "for loops" below will make a LED fade on and off in a "breathing" pattern.

  // Now we'll have the program automatically change the value of brightness
  // using a command called "for".

  // for is like a tiny version of loop. The for command has several parts:
  // 1. something to do before starting (brightness = 0)
  // 2. a test to decide whether to keep going (brightness <= 255)
  // 3. a block of commands to run (everything within the {} below the for)
  // 4. a command to run before doing it again (brightness = brightness + 1)

  // Here's a for command which will start brightness at 0, check to see if it's less than
  // or equal to 255, run the commands after it, then add one to brightness and start over:

  for (brightness = 0; brightness <= 255; brightness = brightness + 1)
  {
    // Within the loop, we'll use brightness variable to control the brightness of the LEDs:

    analogWrite(L2, brightness);

    // NOTE that not all pins work with analogWrite!
    // The ones with a "~" in front of them will change brightness,
    // the others will only turn on if brightness > 128.
    // Both types are used above, run the code and note the difference between them.

    // The delay command controls the speed - if you make the delay larger,
    // it will slow down the loop. Smaller, and it will run faster:

    delay(5);
  }

  // What if we want the LED to start at full brightness and fade to black?
  // We can easily set up the for loop to run in reverse:

  for (brightness = 255; brightness >= 0; brightness = brightness - 1)
  {
    analogWrite(L2, brightness);
    delay(5);
  }
}

