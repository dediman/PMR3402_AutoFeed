#ifndef SERVO_H_INCLUDED
#define SERVO_H_INCLUDED

#include "atuacao.h"

class Servomotor: public Atuacao {
  public:
  Servomotor();
  void setup();
  void activate();

  private:
  int position;
  unsigned long time;
};

#endif // SERVO_H_INCLUDED