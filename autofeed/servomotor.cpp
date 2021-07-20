#include <Arduino.h>
#include <Servo.h>

#include "definitions.h"
#include "servomotor.h"

Servomotor::Servomotor() {}
Servo myservo;

int feedCounter = 10; //armazena numero de giros pelo usuario
int position = 0;

void Servomotor::setup()
{
  myservo.attach(SIGNAL_PIN);   // define pino SIGNAL do servo
  myservo.write(position);
  Serial.println("## SERVO CONECTADO ##");
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
  Serial.println("## SERVO ATIVADO ##");
  if(feedCounter > 0) {
    for (position = 0; position <= 250; position++) { // de 0 a 180 graus
      myservo.write(position);              // movimenta servo ate a posicao
      delay(30);   // aguarda 15ms para o servo atingir a posicao
    }
    for (position = 250; position >= 0; position--) { // de 180 a 0 graus
      myservo.write(position);              // movimenta servo ate a posicao
      delay(30);   // aguarda 15ms para o servo atingir a posicao
    }
    decrementCounter();
  }
  
}