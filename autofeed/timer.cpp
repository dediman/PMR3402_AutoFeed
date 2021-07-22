#include <Arduino.h>

#include "definitions.h"
#include "timer.h"

#define TEMPO 10000 // 10s

Timer::Timer() {}

int timeCounter = 0; //armazena tempo inserido pelo usuario

void Timer::incrementCounter()
{
    timeCounter += 1;
}

void Timer::decrementCounter()
{
    timeCounter -= 1;
}

void Timer::resetCounter()
{
    timeCounter = 0;
}

void Timer::begin()
{
    this->startTime = millis();
}

bool Timer::timeout()
{
    if (millis() - startTime > timeCounter*TEMPO) {
        return TRUE;
    }
    return FALSE;
}