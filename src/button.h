#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "ihm.h"

class Button: public Ihm {
  public:
  Button();
  bool getButton(int button);
};

#endif // BUTTON_H_INCLUDED