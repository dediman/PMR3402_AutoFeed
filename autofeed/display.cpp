#include <Arduino.h>
#include <LiquidCrystal.h>

#include "definitions.h"
#include "display.h"

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

Display::Display() {}

void Display::sendMessage(char col, char row, char message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}

void Display::clear()
{
  lcd.clear();
}

void Display::setup()
{
  lcd.begin(16, 2);
}