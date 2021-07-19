#include <Arduino.h>

#include "button.h"

Button::Button(int pino) : pin(pino) {}

bool Button::getButton()
{
    return digitalRead(pin);
}

void Button::sendMessage(char col, char row, char message) {}
void Button::clear() {}
void Button::setup() {}