#include <Arduino.h>
#include <Servo.h>

#include "definitions.h"
#include "servomotor.h"

Servomotor::Servomotor() {}
Servo myservo;

// int feedCounter = 0; //armazena numero de giros pelo usuario
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
  while(feedCounter > 0) {
    Serial.print("feedCounter= ");
    Serial.println(feedCounter);
    for (position = 0; position <= 250; position++) {
      myservo.write(position);  // movimenta servo ate a posicao
      delay(15);   // aguarda 15ms para o servo atingir a posicao
    }
    for (position = 250; position >= 0; position--) {
      myservo.write(position);  // movimenta servo ate a posicao
      delay(15);   // aguarda 15ms para o servo atingir a posicao
    }
    feedCounter -= 1;
  }
}