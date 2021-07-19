#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "sinalizacao.h"

class Led: public Sinalizacao {
  public:
  Led();
  void toggleLed(int led) = 0;
};

#endif // LED_H_INCLUDED