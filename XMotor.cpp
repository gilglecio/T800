#include <Arduino.h>;
#include <XMotor.h>;

XMotor::XMotor(int _speed_pin, int _in1_pin, int _in2_pin) {
  
    _speed_pin = _speed_pin;
    _in1_pin = _in1_pin;
    _in2_pin = _in2_pin;

    pinMode(_speed_pin, OUTPUT);
    pinMode(_in1_pin, OUTPUT);
    pinMode(_in2_pin, OUTPUT);
}

void XMotor::setSpeed(int speed) {
    _speed_pin = speed;
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