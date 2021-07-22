#ifndef SENSORIAMENTO_H_INCLUDED
#define SENSORIAMENTO_H_INCLUDED

class Sensoriamento {
  public:
  virtual int getDistance() = 0;
  virtual bool lowLevel(unsigned long time) = 0;
};

#endif // SENSORIAMENTO_H_INCLUDED