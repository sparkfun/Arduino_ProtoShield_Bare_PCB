int ledPin = 13;
int buttonPin = 2;

int buttonState = LOW;
int oldButtonState = HIGH;
char serInput;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, HIGH);

  Serial.begin(115200);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (Serial.available() > 0)
  {
    serInput = Serial.read();
    Serial.println("Miny, Moe.");
  }
  if (buttonState != oldButtonState)
  {
    if (buttonState == HIGH)
    {
      digitalWrite(ledPin, HIGH);
      Serial.print("Meeny, ");
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.print("Eeny, ");
    }
  }

  oldButtonState = buttonState;
}
