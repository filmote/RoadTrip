#pragma once

#include <ArduboyTones.h>

namespace Sounds {

    const uint16_t Theme[] PROGMEM = {
        NOTE_D4,461, NOTE_C4,461, NOTE_D4,461, NOTE_F4,230, NOTE_G4,230, NOTE_D4,461, NOTE_C4,461, NOTE_D4,461,
        NOTE_F4,230, NOTE_G4,230, NOTE_DS4,461, NOTE_D4,461, NOTE_DS4,461, NOTE_F4,230, NOTE_G4,230, NOTE_A3,461,
        NOTE_G3,461, NOTE_A3,461, NOTE_AS3,230, NOTE_C4,230,
        TONES_REPEAT
    };

    const uint16_t GameOver[] PROGMEM = {
        NOTE_REST,400,
        NOTE_G5,300, NOTE_F5,300, NOTE_C5,300,
        TONES_END
    };

    const uint16_t Success[] PROGMEM = {
        NOTE_F5,300, NOTE_G5,300,
        TONES_END
    };

    const uint16_t Crash[] PROGMEM = {
        NOTE_C0, 45, NOTE_B1, 15, NOTE_F0, 25, NOTE_C2, 5, NOTE_F0, 15, NOTE_E1, 45, NOTE_F0, 15, TONES_END 
    };

    const uint16_t PassCar[] PROGMEM = {
        NOTE_D6, 60, NOTE_C6, 60, TONES_END
    };

    const uint16_t Alert[] PROGMEM = {
        NOTE_C6, 125, TONES_END
    };

    const uint16_t Drive_00[] PROGMEM = {
        NOTE_A2, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_01[] PROGMEM = {
        NOTE_C2, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_02[] PROGMEM = {
        NOTE_E2, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_03[] PROGMEM = {
        NOTE_A3, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_04[] PROGMEM = {
        NOTE_C3, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_05[] PROGMEM = {
        NOTE_E3, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_06[] PROGMEM = {
        NOTE_A4, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_07[] PROGMEM = {
        NOTE_C4, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t Drive_08[] PROGMEM = {
        NOTE_E4, 10, NOTE_REST, 10, TONES_END
    };

    const uint16_t *Drive[] = { Drive_00, Drive_01, Drive_02, Drive_03, Drive_04, Drive_05, Drive_06, Drive_07, Drive_08 };

}