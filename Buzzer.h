#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer {
    private:
        int _vcc, _gnd;
    public:
        Buzzer(int _vcc, int _gnd);
        void bip();
};

#endif