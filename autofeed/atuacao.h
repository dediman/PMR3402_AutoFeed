#ifndef ATUACAO_H_INCLUDED
#define ATUACAO_H_INCLUDED

class Atuacao {
  public:
  virtual void setup() = 0;
  virtual void incrementCounter() = 0;
  virtual void decrementCounter() = 0;
  virtual void resetCounter() = 0;
  virtual void activate() = 0;
};

#endif // ATUACAO_H_INCLUDED