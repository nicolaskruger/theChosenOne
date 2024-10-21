#include <Arduino.h>

// const
const int showPins[] = {D7, D6, D5};
const int fps = 60;
const int delayFps = 1000 / fps;
const int maxShowTime = 20;

// variable
int countShowTime = 0;
bool show = false;

// put function declarations here:

void setUpShow();
void setUpButton();
void itIsShowTime();
void activeShow();

void setup()
{
  // put your setup code here, to run once:
  setUpShow();
  setUpButton();
}

void loop()
{
  delay(delayFps);
  activeShow();
  if (show)
    itIsShowTime();
  // put your main code here, to run repeatedly:
}

// put function definitions here:
void setUpShow()
{
  for (auto &&pin : showPins)
  {
    pinMode(pin, OUTPUT);
  }
  randomSeed(analogRead(0));
}

void setUpButton()
{
  pinMode(D0, INPUT_PULLUP);
}

void itIsShowTime()
{
  countShowTime++;
  if (countShowTime < maxShowTime)
  {
    return;
  }
  countShowTime = 0;
  for (auto &&pin : showPins)
  {
    digitalWrite(pin, random(2));
  }
}

void activeShow()
{
  show = digitalRead(D0) == LOW ? true : show;
}
