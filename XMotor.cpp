#include <Arduino.h>
#include <XMotor.h>

XMotor::XMotor(uint8_t speed_pin, uint8_t in1_pin, uint8_t in2_pin): _speed_pin(speed_pin), _in1_pin(in1_pin), _in2_pin(in2_pin) {
    pinMode(_speed_pin, OUTPUT);
    pinMode(_in1_pin, OUTPUT);
    pinMode(_in2_pin, OUTPUT);
}

void XMotor::speed(int speed) {
    analogWrite(_speed_pin, speed);
}

void XMotor::stop() {
    digitalWrite(_in1_pin, HIGH);
    digitalWrite(_in2_pin, HIGH);
}

void XMotor::cw() {
    digitalWrite(_in1_pin, HIGH);
    digitalWrite(_in2_pin, LOW);
}

void XMotor::ccw() {
    digitalWrite(_in1_pin, LOW);
    digitalWrite(_in2_pin, HIGH);
}
