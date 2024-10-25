#include <Arduino.h>
#include <LiquidCrystal.h>
#include "melody/zelda_melody.h"
// Definindo as frequências das notas

// const

const auto state_question = 0;
const auto state_success = 1;
const auto state_error = 2;

auto state = state_question;

void (*state_array[3])();

const auto success_button = D5, error_button = D7;

const char *message_question[] = {"Voce aceita ?"};
const char *message_success[] = {"Resposta certa!", "Parabens!!!"};
const char *message_error[] = {"Voce errou,", "Tente novamente!"};

auto count_question = 0;

const int fps = 60;
const int delayFps = 1000 / fps;

const int rs = D8, en = D6, d4 = D3, d5 = D2, d6 = D1, d7 = D0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// put function declarations here:

void question();
void error();
void success();

void print_message_tx(const char *message[]);
void set_up_state();

void setup()
{

  void set_up_state();

  lcd.begin(16, 2);
  print_message_tx(message_question);

  // lcd.cursor();
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

  state_array[state_question] = question;
  state_array[state_success] = success;
  state_array[state_error] = error;
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

auto readButtons()
{
  int arr[] = {digitalRead(success_button), digitalRead(error_button)};
  return arr;
}

void question()
{
  auto [s_button, e_button] = *reinterpret_cast<int(*)[2]>(readButtons());
  if (!s_button)
  {
    print_message_tx(message_success);
    state = state_success;
  }
  if (true)
  {
    print_message_tx(message_error);
    state = state_error;
  }
  return;
}

auto count_success = 0;

void success()
{
}

auto count_error = 0;
auto count_out_error = 0;

void error()
{
  if (countTime(&count_question, 3000))
  {
    print_message_tx(message_question);
    state = state_question;
  }
}

void print_message_tx(const char *message[])
{
  lcd.clear();
  int lines = 1;
  for (auto line = 0; line < lines; line++)
  {
    lcd.setCursor(0, line);
    lcd.print(message[line]);
  }
}