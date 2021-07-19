#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

#include "ihm.h"

class Lcd: public Ihm {
  public:
  Lcd();
  void sendMessage(char col, char row, char message);
  void clear();
  void setup();
  bool getButton();
};

#endif // LCD_H_INCLUDED