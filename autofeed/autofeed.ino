#include <Arduino.h>

#include "definitions.h"
#include "buzzer.h"
#include "button.h"
#include "lcd.h"
#include "led.h"
#include "servomotor.h"
#include "ultrassonic.h"

// Instanciamento de Classes
Buzzer buz;
Button btn;
Lcd lcd;
Led led;
Servomotor ser;
Ultrassonic ult;

// Variaveis Globais
int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

// Maquina de Estados
void iniciaMaquinaEstados()
{
  for (int i = 0; i < NUM_ESTADOS; i++) {
    for (int j = 0; j < NUM_EVENTOS; j++) {
       acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
       proximo_estado_matrizTransicaoEstados[i][j] = i;
    }
  }
  proximo_estado_matrizTransicaoEstados[DEFINIR_TEMPO][INCREMENTAR] = DEFINIR_TEMPO;
  acao_matrizTransicaoEstados[DEFINIR_TEMPO][INCREMENTAR] = A01;

  proximo_estado_matrizTransicaoEstados[DEFINIR_TEMPO][DECREMENTAR] = DEFINIR_TEMPO;
  acao_matrizTransicaoEstados[DEFINIR_TEMPO][DECREMENTAR] = A02;

  proximo_estado_matrizTransicaoEstados[DEFINIR_TEMPO][CONFIRMAR] = DEFINIR_PORCOES;
  acao_matrizTransicaoEstados[DEFINIR_TEMPO][CONFIRMAR] = A04;

  proximo_estado_matrizTransicaoEstados[DEFINIR_PORCOES][INCREMENTAR] = DEFINIR_PORCOES;
  acao_matrizTransicaoEstados[DEFINIR_PORCOES][INCREMENTAR] = A01;

  proximo_estado_matrizTransicaoEstados[DEFINIR_PORCOES][DECREMENTAR] = DEFINIR_PORCOES;
  acao_matrizTransicaoEstados[DEFINIR_PORCOES][DECREMENTAR] = A02;

  proximo_estado_matrizTransicaoEstados[DEFINIR_PORCOES][REDEFINIR] = DEFINIR_TEMPO;
  acao_matrizTransicaoEstados[DEFINIR_PORCOES][REDEFINIR] = A03;

  proximo_estado_matrizTransicaoEstados[DEFINIR_PORCOES][CONFIRMAR] = EM_OPERACAO;
  acao_matrizTransicaoEstados[DEFINIR_PORCOES][CONFIRMAR] = A03;

  proximo_estado_matrizTransicaoEstados[EM_OPERACAO][REDEFINIR] = DEFINIR_TEMPO;
  acao_matrizTransicaoEstados[EM_OPERACAO][REDEFINIR] = A03;

  proximo_estado_matrizTransicaoEstados[EM_OPERACAO][TEMPO_ATINGIDO] = LIBERANDO_RACAO;
  acao_matrizTransicaoEstados[EM_OPERACAO][TEMPO_ATINGIDO] = A05;

  proximo_estado_matrizTransicaoEstados[EM_OPERACAO][TEMPO_NAO_ATINGIDO] = EM_OPERACAO;
  acao_matrizTransicaoEstados[EM_OPERACAO][TEMPO_NAO_ATINGIDO] = A06;

  proximo_estado_matrizTransicaoEstados[LIBERANDO_RACAO][RACAO_LIBERADA] = EM_OPERACAO;
  acao_matrizTransicaoEstados[LIBERANDO_RACAO][RACAO_LIBERADA] = A07;

} // iniciaMaquinaEstados


void setup() {
  
  // comunicacoes
  Serial.begin(9600);
  Serial.println("Inicializando...");
  lcd.setup();
  lcd.clear();

  // mensagem inicial
  Serial.println("Mensagem inicial...");
  for (int i = 0; i <= 15; i++) {
    lcd.sendMessage(0, 0, "    AutoFeed");
    lcd.sendMessage(i, 1, "*");
    delay(200);
    lcd.clear();
  }
  buz.buzz(TURN_ON);
  
  Serial.println("## INICIALIZACAO COMPLETA ##");
}


void loop() {

  

}