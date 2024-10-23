#include <Arduino.h>

#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 493
#define NOTE_C5 523

// const
const int showPins[] = {D7, D6, D5};
const int fps = 60;
const int delayFps = 1000 / fps;
const int maxShowTime = 20;
const int buttonPin = D0;
const int buzzerPin = D1;

// variable
int countShowTime = 0;
bool show = false;
bool activeBuzzer = false;

// Melodia da música de Zelda (introdução)
const int melody[] = {
    NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, // Primeiras notas
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, // Seguintes notas
    NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, // Repetição
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4  // Fim
};

// Duração de cada nota (em milissegundos)
const int noteDurations[] = {
    300, 300, 300, 600, // Duração das primeiras notas
    300, 300, 300, 600, // Seguintes
    300, 300, 300, 600, // Repetição
    300, 300, 300, 600  // Fim
};

int currentTime = 0;
const int noteSize = 16;
int currentNote;

// put function declarations here:

void setUpShow();
void setUpButton();
void setUpBuzzer();

void itIsShowTime();

void lightShow();
void buzzerShow();
void activeShow();

void setup()
{
  // put your setup code here, to run once:
  setUpShow();
  setUpButton();
  setUpBuzzer();
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

void setUpBuzzer()
{
  pinMode(buzzerPin, OUTPUT);
}

void setUpButton()
{
  pinMode(buttonPin, INPUT_PULLUP);
}

void lightShow()
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

void buzzerShow()
{

  const auto duration = noteDurations[currentNote];
  if (currentTime >= duration)
  {
    currentTime = 0;
    currentNote = (currentNote + 1) % noteSize;
  }
  const auto mel = melody[currentNote];
  tone(buzzerPin, mel);
  currentTime += delayFps;
}

void itIsShowTime()
{
  lightShow();
  buzzerShow();
}

void activeShow()
{
  show = digitalRead(D0) == LOW ? true : show;
}
