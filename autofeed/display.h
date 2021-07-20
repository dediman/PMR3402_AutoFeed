#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "visualizacao.h"

class Display: public Visualizacao {
  public:
  Display();
  void sendMessage(char col, char row, char message);
  void clear();
  void setup();
};

#endif // DISPLAY_H_INCLUDED