#include <Arduino.h>
#include <Servo.h>

#include "definitions.h"
#include "servomotor.h"

Servo myservo;

Servomotor::Servomotor() {}

int feedCounter = 0; //armazena numero de giros pelo usuario

void Servomotor::setup()
{
  myservo.attach(SIGNAL_PIN);   // define pino SIGNAL do servo
}

void Servomotor::incrementCounter()
{
    feedCounter += 1;
}

void Servomotor::decrementCounter()
{
  if (feedCounter >= 0) {
    feedCounter -= 1;
    }
}

void Servomotor::resetCounter()
{
    feedCounter = 0;
}

void Servomotor::activate()
{
  if(feedCounter > 0) {
    time = millis();
    for (position = 0; position <= 180; position++) { // de 0 a 180 graus
      myservo.write(position);              // movimenta servo ate a posicao
      delay(15);   // aguarda 15ms para o servo atingir a posicao
    }
    time = millis();
    for (position = 180; position >= 0; position--) { // de 180 a 0 graus
      myservo.write(position);              // movimenta servo ate a posicao
      delay(15);   // aguarda 15ms para o servo atingir a posicao
    }
    decrementCounter();
  }
  
}