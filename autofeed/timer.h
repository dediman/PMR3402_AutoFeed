#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "temporizacao.h"

class Timer: public Temporizacao {
  public:
  Timer();
  void begin();
  bool timeout();

  private:
  unsigned long startTime;
};

#endif // TIMER_H_INCLUDED