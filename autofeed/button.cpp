#include <Arduino.h>

#include "button.h"

Button::Button(int pino) : pin(pino) {}

bool Button::getButton()
{
    return digitalRead(pin);
}