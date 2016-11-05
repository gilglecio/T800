#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer {
    private:
        uint8_t _vcc, _gnd;
    public:
        Buzzer(uint8_t vcc, uint8_t gnd);
        void bip();
};

#endif