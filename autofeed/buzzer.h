#ifndef BUZZER_H_INCLUDED
#define BUZZER_H_INCLUDED

#include "sinalizacao.h"

class Buzzer: public Sinalizacao {
  public:
  Buzzer();
  void buzz(int type);
  void toggleLed();
};

#endif // BUZZER_H_INCLUDED