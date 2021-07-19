#include <Arduino.h>

#include "led.h"

Led::Led(int pino) : pin(pino) {}

void Led::toggleLed()
{
   digitalWrite(pin, !digitalRead(pin));
}