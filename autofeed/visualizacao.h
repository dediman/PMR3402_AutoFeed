#ifndef VISUALIZACAO_H
#define VISUALIZACAO_H

class Visualizacao {
  public:
  virtual void sendMessage(char col, char row, char message) = 0;
  virtual void clear() = 0;
  virtual void setup() = 0;
};

#endif // VISUALIZACAO_H

