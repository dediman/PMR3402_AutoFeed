#include <Arduino.h>

#include "definitions.h"
#include "buzzer.h"
#include "button.h"
#include "lcd.h"
#include "led.h"
#include "servomotor.h"
#include "timer.h"
#include "ultrassonic.h"

// Instanciamento de Classes
Buzzer buz;
Button btn1(PLUS_PIN);
Button btn2(MINUS_PIN);
Button btn3(ENTER_PIN);
Button btn4(REDEFINE_PIN);
Lcd lcd;
Led redled(RED_LED_PIN);
Led greenled(GREEN_LED_PIN);
Servomotor ser;
Timer tmr;
Ultrassonic ult;

// Variaveis Globais
int codigoEvento = NENHUM_EVENTO;
int eventoInterno = NENHUM_EVENTO;
int estado = DEFINIR_TEMPO;
int codigoAcao;
int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

extern typedef struct {
  int timeCounter; //armazena tempo inserido pelo usuario
  int feedCounter; //armazena numero de giros pelo usuario
} StateVar;

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

  proximo_estado_matrizTransicaoEstados[EM_OPERACAO][NIVEL_BAIXO] = EM_OPERACAO;
  acao_matrizTransicaoEstados[EM_OPERACAO][NIVEL_BAIXO] = A07;

  proximo_estado_matrizTransicaoEstados[LIBERANDO_RACAO][RACAO_LIBERADA] = EM_OPERACAO;
  acao_matrizTransicaoEstados[LIBERANDO_RACAO][RACAO_LIBERADA] = A06;

} // iniciaMaquinaEstados

void iniciaSistema()
{
  iniciaMaquinaEstados();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PLUS_PIN, INPUT);
  pinMode(MINUS_PIN, INPUT);
  pinMode(ENTER_PIN, INPUT);
  pinMode(REDEFINE_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SIGNAL_PIN, OUTPUT);

  greenled.toggleLed();

} // initSystem


int executarAcao(int codigoAcao, int estado)
{
  int retval;

  retval = NENHUM_EVENTO;
  if (codigoAcao == NENHUMA_ACAO)
    return retval;

  switch(codigoAcao)
  {
  case A01:
    if (estado == DEFINIR_TEMPO) {
      StateVar.timeCounter += 1;
    }
    else {  // estado == DEFINIR_PORCOES
      StateVar.timeCounter += 1;
    }
    break;
  case A02:
    if (estado == DEFINIR_TEMPO) {
      StateVar.feedCounter -= 1;
    }
    else {  // estado == DEFINIR_PORCOES
      StateVar.feedCounter -= 1;
    }
    break;
  case A03:
    StateVar.timeCounter = 0;
    StateVar.feedCounter = 0;
    break;
  case A04:
    if (estado == DEFINIR_PORCOES) {
      tmr.begin();
    }
    buz.buzz(CONFIRMED);
    break;
  case A05:
    ser.activate();
    buz.buzz(SERVED);
    break;
  case A06:
    tmr.begin();
    break;
  case A07:
    redled.toggleLed();
    break;
  } // switch

  return retval;
} // executarAcao

int obterEvento()
{
  int retval = NENHUM_EVENTO;

  if (btn1.getButton())
    return INCREMENTAR;
  if (btn2.getButton())
    return DECREMENTAR;
  if (btn3.getButton())
    return CONFIRMAR;
  if (btn4.getButton())
    return REDEFINIR;
  if (tmr.timeout())
    return TEMPO_ATINGIDO;
  if (ult.getDistance() < DIST_BAIXO)
    return NIVEL_BAIXO;

  return retval;

} // obterEvento


int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao

int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


void setup() {

  // inicializacao
  Serial.begin(9600);
  Serial.println("Inicializando...");
  iniciaSistema();
  lcd.setup();
  lcd.clear();

  // mensagem inicial
  Serial.println("## BEM-VINDX ##");
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

  if (eventoInterno == NENHUM_EVENTO) {
      codigoEvento = obterEvento();
  } else {
      codigoEvento = eventoInterno;
  }
  if (codigoEvento != NENHUM_EVENTO)
  {
      codigoAcao = obterAcao(estado, codigoEvento);
      estado = obterProximoEstado(estado, codigoEvento);
      eventoInterno = executarAcao(codigoAcao, estado);
      Serial.print("Estado: ");
      Serial.print(estado);
      Serial.print(" Evento: ");
      Serial.print(codigoEvento);
      Serial.print(" Acao: ");
      Serial.println(codigoAcao);
  }


}