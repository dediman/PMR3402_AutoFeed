#ifndef TEMPORIZACAO_H_INCLUDED
#define TEMPORIZACAO_H_INCLUDED

class Temporizacao {
  public:
  virtual void begin() = 0;
  virtual void incrementCounter() = 0;
  virtual void decrementCounter() = 0;
  virtual void resetCounter() = 0;
  virtual bool timeout() = 0;
};

#endif // TEMPORIZACAO_H_INCLUDED