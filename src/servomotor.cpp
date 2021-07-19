#include <Arduino.h>
#include <Servo.h>

#include "definitions.h"
#include "servomotor.h"

Servo myservo;

Servomotor::Servomotor() {}

void Servomotor::setup()
{
  myservo.attach(SIGNAL_PIN);   // define pino SIGNAL do servo
}

void Servomotor::activate()
{
  time = milis();
  for (position = 0; position <= 180; position++) { // de 0 a 180 graus
    myservo.write(position);              // movimenta servo ate a posicao
    while( (milis()-time) != 15 );   // aguarda 15ms para o servo atingir a posicao
  }
  time = milis();
  for (position = 180; position >= 0; position--) { // de 180 a 0 graus
    myservo.write(position);              // movimenta servo ate a posicao
    while( (milis()-time) != 15 );   // aguarda 15ms para o servo atingir a posicao
  }
}