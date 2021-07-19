#include <Arduino.h>

#include "led.h"

Led::Led() {}

void Led::toggleLed(int led)
{
   digitalWrite(led, !digitalRead(led));
}