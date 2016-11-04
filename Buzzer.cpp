#include <Arduino.h>;
#include <Buzzer.h>;

Buzzer::Buzzer(int _vcc, int _gnd) {

    _vcc = _vcc;
    _gnd = _gnd;

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