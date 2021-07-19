#include <Arduino.h>

#include "definitions.h"
#include "timer.h"

#define TEMPO 30 // minutos

Timer::Timer() {}

void Timer::begin()
{
    startTime = millis();
}

bool Timer::timeout()
{
    if (millis() - startTime > StateVar.timeCounter*TEMPO) {
        return TRUE;
    }
    return FALSE;
}