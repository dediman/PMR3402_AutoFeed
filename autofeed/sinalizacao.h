#ifndef SINALIZACAO_H_INCLUDED
#define SINALIZACAO_H_INCLUDED

class Sinalizacao {
  public:
  virtual void begin() = 0;
  virtual void activate(int mode) = 0;
};

#endif // SINALIZACAO_H_INCLUDED