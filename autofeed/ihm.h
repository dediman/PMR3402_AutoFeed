#ifndef IHM_H
#define IHM_H

class Ihm {
  public:
  virtual void sendMessage(char col, char row, char message) = 0;
  virtual void clear() = 0;
  virtual void setup() = 0;
  virtual bool getButton() = 0;
};

#endif // IHM_H
