#include <Arduino.h>

#include "button.h"

Button::Button(int pino) : pin(pino) {}

int buttonState;
int lastButtonState = 0;
int reading;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void Button::begin()
{
    pinMode(pin, OUTPUT);
}

bool Button::getButton()
{
  reading = digitalRead(pin);
  Serial.print("LEITURA BOTAO: ");
  Serial.println(reading);
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    Serial.println("SWITCH CHANGED");
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("DEBOUNCE");
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
  Serial.print("BUTTON STATE = ");
  Serial.println(buttonState);
  return buttonState;
}

