#include <Arduino.h>

#include "button.h"

Button::Button(int pino) : pin(pino) {}

void Button::getButton()
{
    return digitalRead(pin);
}