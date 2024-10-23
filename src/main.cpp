#include <Arduino.h>

// Definindo as frequências das notas
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 493
#define NOTE_C5 523
#define NOTE_D5 587

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

// Melodia do tema principal (simplificada)
int melody[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
    NOTE_C4, NOTE_E4, NOTE_A4};

// Duração de cada nota (em milissegundos)
int noteDurations[] = {
    300, 300, 600, 150,
    150, 300, 300, 300,
    300, 300, 300, 300,
    300, 300, 300, 300,
    300, 300, 600};

int currentTime = 0;
const int noteSize = 19;
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
