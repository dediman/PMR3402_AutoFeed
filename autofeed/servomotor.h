#ifndef SERVO_H_INCLUDED
#define SERVO_H_INCLUDED

#include "atuacao.h"

class Servomotor: public Atuacao {
  public:
  Servomotor();
  void setup();
  void incrementCounter();
  void decrementCounter();
  void resetCounter();
  void activate();

  private:
  int position;
  unsigned long time;
};

#endif // SERVO_H_INCLUDED