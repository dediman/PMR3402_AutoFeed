#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "sinalizacao.h"

class Led: public Sinalizacao {
  public:
  Led(int pino);
  void toggleLed() = 0;

  private:
  int pin;
};

#endif // LED_H_INCLUDED