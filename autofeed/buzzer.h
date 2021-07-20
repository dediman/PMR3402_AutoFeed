#ifndef BUZZER_H_INCLUDED
#define BUZZER_H_INCLUDED

#include "sinalizacao.h"

class Buzzer: public Sinalizacao {
  public:
  Buzzer(int pino);
  void begin();
  void activate(int mode);

  private:
  int pin;
};

#endif // BUZZER_H_INCLUDED