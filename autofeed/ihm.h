#ifndef IHM_H
#define IHM_H

class Ihm {
  public:
  virtual void begin() = 0;
  virtual bool getButton() = 0;
};

#endif // IHM_H
