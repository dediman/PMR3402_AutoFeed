#include <Arduino.h>

#include "definitions.h"
#include "buzzer.h"
#include "button.h"
#include "lcd.h"
#include "led.h"

// instanciamento de classes
Buzzer buz;
Button btn;
Lcd lcd;
Led led;

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