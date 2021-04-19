#pragma once

#include <ArduboyTones.h>

namespace Sounds {

    const uint16_t Theme[] PROGMEM = {
        // 0x0062,0x015E, 0x0057,0x00AF, 0x0057,0x00AF, 0x0057,0x00AF, 0x0057,0x00AF, 0x0057,0x00AF, 0x0062,0x020D, 0x0057,0x00AF, 0x0057,0x00AF, 
        // 0x0057,0x00AF, 0x0057,0x00AF, 0x0062,0x020D, 0x0057,0x020D, 0x0057,0x00AF, 0x0057,0x00AF, 0x0057,0x00AF, 0x0057,0x00AF, 
        // 0x0057,0x00AF, 0x0049,0x020D, 0x0049,0x00AF, 0x0049,0x00AF, 0x0049,0x00AF, 0x0049,0x00AF, TONES_REPEAT
        0x00c4,0x015E, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00c4,0x020D, 0x00ae,0x00AF, 0x00ae,0x00AF, 
        0x00ae,0x00AF, 0x00ae,0x00AF, 0x00c4,0x020D, 0x00ae,0x020D, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00ae,0x00AF, 0x00ae,0x00AF, 
        0x00ae,0x00AF, 0x0092,0x020D, 0x0092,0x00AF, 0x0092,0x00AF, 0x0092,0x00AF, 0x0092,0x00AF, TONES_REPEAT
    };

    const uint16_t GameOver[] PROGMEM = {
        0x0106,0x041A, 0x014A,0x00AF, 0x0000,0x015E, 0x014A,0x015E, 0x0000,0x00AF, 0x0106,0x02BC, 0x00F7,0x020D, 0x0106,0x02BC,
        TONES_END
    };

    const uint16_t Success[] PROGMEM = {
        NOTE_F5,300, NOTE_G5,300,
        TONES_END
    };

    const uint16_t Lights_Short[] PROGMEM = {
        NOTE_F5, 60, TONES_END
    };

    const uint16_t Lights_Long[] PROGMEM = {
        NOTE_F6, 300, TONES_END
    };
 
    const uint16_t Crash[] PROGMEM = {
        // NOTE_C0, 45, NOTE_B1, 15, NOTE_F0, 25, NOTE_C2, 5, NOTE_F0, 15, NOTE_E1, 45, NOTE_F0, 15, TONES_END 
        NOTE_C2, 90, NOTE_E2, 15, NOTE_D2, 80, NOTE_A2, 26, TONES_END 
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