#include <Arduino.h>

// Definindo as frequências das notas
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0

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

int melody[] = {

    // Based on the arrangement at https://www.flutetunes.com/tunes.php?id=169

    NOTE_AS4,
    NOTE_F4,
    NOTE_F4,
    NOTE_AS4, // 1
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_AS4,
    NOTE_FS4,
    NOTE_FS4,
    NOTE_AS4,
    NOTE_A4,
    NOTE_G4,
    NOTE_A4,
    REST,

    NOTE_AS4,
    NOTE_F4,
    NOTE_AS4,
    NOTE_AS4,
    NOTE_C5,
    NOTE_D5,
    NOTE_DS5, // 7
    NOTE_F5,
    NOTE_F5,
    NOTE_F5,
    NOTE_F5,
    NOTE_FS5,
    NOTE_GS5,
    NOTE_AS5,
    NOTE_AS5,
    NOTE_AS5,
    NOTE_GS5,
    NOTE_FS5,
    NOTE_GS5,
    NOTE_FS5,
    NOTE_F5,
    NOTE_F5,

    NOTE_DS5,
    NOTE_F5,
    NOTE_FS5,
    NOTE_F5,
    NOTE_DS5, // 11
    NOTE_CS5,
    NOTE_DS5,
    NOTE_F5,
    NOTE_DS5,
    NOTE_CS5,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_G5,
    NOTE_F5,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,

    NOTE_AS4,
    NOTE_F4,
    NOTE_AS4,
    NOTE_AS4,
    NOTE_C5,
    NOTE_D5,
    NOTE_DS5, // 15
    NOTE_F5,
    NOTE_F5,
    NOTE_F5,
    NOTE_F5,
    NOTE_FS5,
    NOTE_GS5,
    NOTE_AS5,
    NOTE_CS6,
    NOTE_C6,
    NOTE_A5,
    NOTE_F5,
    NOTE_FS5,
    NOTE_AS5,
    NOTE_A5,
    NOTE_F5,
    NOTE_F5,

    NOTE_FS5,
    NOTE_AS5,
    NOTE_A5,
    NOTE_F5,
    NOTE_D5,
    NOTE_DS5,
    NOTE_FS5,
    NOTE_F5,
    NOTE_CS5,
    NOTE_AS4,
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_G5,
    NOTE_F5,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4,
    NOTE_F4

};

// Duração de cada nota (em milissegundos)
int noteDurations[] = {
    (int)(1.5 * 2), 8, 8, 8, // 1
    16, 16, (int)(1.5 * 2),
    (int)(1.5 * 2), 8, 8, 8,
    16, 16, (int)(1.5 * 2),
    1, 4, (int)(1.5 * 4), 8, 16, 16, 16, 16, // 7
    2, 8, 8, 8, 16, 16,
    (int)(1.5 * 2), 8, 8, 8, 16,
    (int)(1.5 * 8), 16, 2, 4,

    (int)(1.5 * 8), 16, 2, 8, 8, // 11
    (int)(1.5 * 8), 16, 2, 8, 8,
    (int)(1.5 * 8), 16, 2, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 8,

    4, (int)(1.5 * 4), 8, 16, 16, 16, 16, // 15
    2, 8, 8, 8, 16, 16,
    (int)(1.5 * 2), 4,
    4, 2, 4,
    (int)(1.5 * 2), 4,
    4, 2, 4,

    (int)(1.5 * 2), 4,
    4, 2, 4,
    (int)(1.5 * 2), 4,
    4, 2, 4,
    (int)(1.5 * 8), 16, 2, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 8};

int currentTime = 0;
const int noteSize = sizeof(melody) / sizeof(melody[0]);
int currentNote;
const int tempo = 88;
const int wholeNote = (60000 * 4) / tempo;

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

  const auto duration = wholeNote / noteDurations[currentNote];
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
