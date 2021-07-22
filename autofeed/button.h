#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "ihm.h"

class Button: public Ihm {
  public:
  Button(int pino);
  void begin();
  bool getButton();
  int buttonState;
  int lastButtonState = 0;
  int reading = 0;
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 50;

  private:
  int pin;
};

#endif // BUTTON_H_INCLUDED