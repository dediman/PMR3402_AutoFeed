#include <Arduino.h>

#include "button.h"

Button::Button() {}

void Button::getButton(int button)
{
    return digitalRead(button);
}