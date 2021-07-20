#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "ihm.h"

class Button: public Ihm {
  public:
  Button(int pino);
  void begin();
  bool getButton();

  private:
  int pin;
};

#endif // BUTTON_H_INCLUDED