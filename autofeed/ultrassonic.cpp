#include <Arduino.h>

#include "definitions.h"
#include "ultrassonic.h"

Ultrassonic::Ultrassonic() {}

int Ultrassonic::getDistance()
{
  // Limpa o pino TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Ativa pino TRIG por 10us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Le o pino ECHO e retona tempo percorrido pela onda sonora em us
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculo da distancia
  distance = duration * 0.017; // Velocidade do som / 2 (ida e volta)
  // Exibe distancia no serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  // Retorna distancia
  return distance;
}