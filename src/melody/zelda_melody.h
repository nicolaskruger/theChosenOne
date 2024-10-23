#include "notes.h"

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

const int noteSize = sizeof(melody) / sizeof(melody[0]);
const int tempo = 88;
const int wholeNote = (60000 * 4) / tempo;