#ifndef SINALIZACAO_H_INCLUDED
#define SINALIZACAO_H_INCLUDED

class Sinalizacao {
  public:
  virtual void toggleLed() = 0;
  virtual void buzz(int type) = 0;
};

#endif // SINALIZACAO_H_INCLUDED