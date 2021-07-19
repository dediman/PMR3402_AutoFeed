#ifndef ULTRASSONIC_H_INCLUDED
#define ULTRASSONIC_H_INCLUDED

#include "sensoriamento.h"

class Ultrassonic: public Sensoriamento {
  public:
  Ultrassonic();
  int getDistance();

  private:
  long duration;
  int distance;
};

#endif // ULTRASSONIC_H_INCLUDED