#include <Arduino.h>

#include "led.h"

Led::Led(int pino) : pin(pino) {}

void Led::begin() {
   pinMode(pin, OUTPUT);
}

void Led::activate(int mode)
{
   modo = mode;
   digitalWrite(pin, modo);
}

void Led::toggleLed()
{
   modo = !modo;
   activate(modo);
}