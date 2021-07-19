#include <Arduino.h>

#include "definitions.h"
#include "timer.h"

#define TEMPO 30 // minutos

Timer::Timer() {}

void Timer::begin()
{
    startTime = milis();
}

bool Timer::timeout()
{
    if (milis() - startTime > StateVar.timeCounter*TEMPO) {
        return TRUE;
    }
    return FALSE;
}