#include <Arduino.h>

#include "button.h"

Button::Button(int pino) : pin(pino) {}

void Button::begin()
{
    pinMode(pin, OUTPUT);
}
bool Button::getButton()
{
    return digitalRead(pin);
}

