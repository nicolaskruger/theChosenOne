#include <Arduino.h>
#include <LiquidCrystal.h>
#include "melody/zelda_melody.h"
// Definindo as frequências das notas

// const

const auto state_question = 0;
const auto state_success = 1;
const auto state_error = 2;

auto state = state_question;

const auto success_button = D5, error_button = D7;

const char *message_question[] = {"Voce aceita ?", ""};
const char *message_success[] = {"Resposta certa!", "Parabens!!!"};
const char *message_error[] = {"Voce errou,", "Tente novamente!"};

auto count_question = 0;

const int fps = 60;
const int delayFps = 1000 / fps;

const int rs = D8, en = D6, d4 = D3, d5 = D2, d6 = D1, d7 = D0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void question();
void error();
void success();

void (*state_array[3])() = {question, success, error};

void print_message_tx(const char *message[]);
void set_up_state();

const auto arr_size = 10;

void setup()
{

  void set_up_state();

  lcd.begin(16, 2);
  print_message_tx(message_question);
}

void loop()
{
  delay(delayFps);

  state_array[state]();
}

void set_up_state()
{
  pinMode(success_button, INPUT_PULLUP);
  pinMode(error_button, INPUT_PULLUP);
}

bool countTime(int *count, int max)
{
  *count += delayFps;
  if (*count >= max)
  {
    *count = 0;
    return true;
  }
  return false;
}

bool one_error = true;

void question()
{
  const auto s_button = digitalRead(success_button);
  const auto e_button = digitalRead(error_button);

  if (s_button == LOW)
  {
    print_message_tx(message_success);
    state = state_success;
    return;
  }
  if (e_button == LOW && one_error)
  {
    one_error = false;
    print_message_tx(message_error);
    state = state_error;
    return;
  }
  return;
}

auto count_success = 0;

void success()
{
}

auto count_error = 0;

void error()
{
  if (countTime(&count_error, 3000))
  {
    print_message_tx(message_question);
    state = state_question;
  }
}

void print_message_tx(const char *message[])
{
  lcd.clear();
  int lines = 2;
  for (auto line = 0; line < lines; line++)
  {
    lcd.setCursor(0, line);
    lcd.print(message[line]);
  }
}