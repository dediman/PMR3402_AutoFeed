#include <Arduino.h>

#include "definitions.h" 
#include "buzzer.h"

// frequencias das melodias a serem reproduzidas
int turnon[] = {131, 165, 196}; // C3, E3, G3 - do maior
int confirmed[] = {466, 494};   // AS4, B4
int served[] = {175, 220, 262}; // F3, A3, C4 - fa maior

Buzzer::Buzzer(int pino) : pin(pino) {}

void Buzzer::begin()
{
    pinMode(pin, OUTPUT);
}

void Buzzer::activate(int mode)
{
    if (mode == TURN_ON) {
        for (int note = 0; note < 4; note++) {
            tone(BUZZER_PIN,turnon[note],250);
            delay(325);
            noTone(BUZZER_PIN);
        }
    }
    else if (mode == CONFIRMED) {
        for (int note = 0; note < 3; note++) {
            tone(BUZZER_PIN,confirmed[note],250);
            delay(325);
            noTone(BUZZER_PIN);
        }
    }
    else if (mode == SERVED) {
        for (int note = 0; note < 4; note++) {
            tone(BUZZER_PIN,confirmed[note],250);
            delay(325);
            noTone(BUZZER_PIN);
        }
    }
}

