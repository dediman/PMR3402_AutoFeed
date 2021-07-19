#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "ihm.h"

class Button: public Ihm {
  public:
  Button(int pino);
  bool getButton();
  void sendMessage(char col, char row, char message);
  void clear();
  void setup();

  private:
  int pin;
};

#endif // BUTTON_H_INCLUDED