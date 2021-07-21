#include <Arduino.h>

#include "definitions.h"
#include "pitches.h"
#include "buzzer.h"

// frequencias das melodias a serem reproduzidas
int turnon[] = {NOTE_C3, NOTE_E3, NOTE_G3};
int confirmed[] = {NOTE_AS4, NOTE_B4};
int served[] = {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4};

Buzzer::Buzzer(int pino) : pin(pino) {}

void Buzzer::begin()
{
    pinMode(pin, OUTPUT);
}

void Buzzer::activate(int mode)
{
    if (mode == TURN_ON) {
        for (int note = 0; note < 4; note++) {
            tone(BUZZER_PIN,turnon[note],400);
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
        for (int note = 0; note < 9; note++) {
            tone(BUZZER_PIN,confirmed[note],300);
            delay(325);
            noTone(BUZZER_PIN);
        }
    }
}

