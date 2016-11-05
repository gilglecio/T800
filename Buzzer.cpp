#include <Arduino.h>
#include <Buzzer.h>

Buzzer::Buzzer(uint8_t vcc, uint8_t gnd): _vcc(vcc), _gnd(gnd) {

    pinMode(_vcc, OUTPUT);
    pinMode(_gnd, OUTPUT);

    digitalWrite(_gnd, LOW);
    digitalWrite(_vcc, LOW);
}

void Buzzer::bip() {
    digitalWrite(_vcc, HIGH);
    delay(100);
    digitalWrite(_vcc, LOW);
}
