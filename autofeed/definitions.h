#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

// GENERAL
#define TRUE 1
#define FALSE 0

// MAQUINA DE ESTADOS
#define NUM_ESTADOS 4
#define NUM_EVENTOS 7
// Estados
#define DEFINIR_TEMPO       0
#define DEFINIR_PORCOES     1
#define EM_OPERACAO         2
#define LIBERANDO_RACAO     3
// Eventos
#define NENHUM_EVENTO      -1
#define INCREMENTAR         0
#define DECREMENTAR         1
#define CONFIRMAR           2
#define REDEFINIR           3
#define TEMPO_ATINGIDO      4
#define RACAO_LIBERADA      5
#define NIVEL_BAIXO         6
// Acoes
#define NENHUMA_ACAO -1
#define A01  0
#define A02  1
#define A03  2
#define A04  3
#define A05  4
#define A06  5
#define A07  6

// BUZZER
#define BUZZER_PIN  8
#define TURN_ON     0
#define CONFIRMED   1
#define SERVED      2

// LED
#define GREEN_LED_PIN   13
#define RED_LED_PIN     12

// LCD
#define RS 2
#define EN 3
#define D4 A2
#define D5 A3
#define D6 A4
#define D7 A5
// Messages
#define CHEIO "Cheio"
#define VAZIO "Vazio"

// BUTTONS
#define PLUS_PIN        4
#define MINUS_PIN       5
#define ENTER_PIN       6
#define REDEFINE_PIN    7

// ULTRASSONIC
#define TRIG_PIN    10
#define ECHO_PIN    11
#define DIST_BAIXO  20

// SERVO
#define SIGNAL_PIN 9

#endif // DEFINITIONS_H_INCLUDED