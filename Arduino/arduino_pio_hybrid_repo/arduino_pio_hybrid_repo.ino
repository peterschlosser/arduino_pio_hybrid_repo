// Arduino Uno Blink sketch
// This is an example project sketch to demonstrate the Arduino IDE and
// PlatformIO hybrid repository.
#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
