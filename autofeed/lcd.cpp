#include <Arduino.h>
#include <LiquidCrystal.h>

#include "definitions.h"
#include "lcd.h"

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

Lcd::Lcd() {}

void Lcd::sendMessage(char col, char row, char message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}

void Lcd::clear()
{
  lcd.clear();
}

void Lcd::setup()
{
  lcd.begin(16, 2);
}

bool Lcd::getButton() {}