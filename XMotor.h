#ifndef XMotor_h
#define XMotor_h

#include "Arduino.h"

class XMotor {
    private:
        uint8_t _speed_pin, _in1_pin, _in2_pin;
    public:
        XMotor(uint8_t speed_pin, uint8_t in1_pin, uint8_t in2_pin);
        void speed(int speed);
        void stop();
        void cw();
        void ccw();
};

#endif