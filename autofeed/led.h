#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "sinalizacao.h"

class Led: public Sinalizacao {
  public:
  Led(int pino);
  void begin();
  void activate(int mode);
  void toggleLed();

  private:
  int pin;
  int modo;
};

#endif // LED_H_INCLUDED