#ifndef XMotor_h
#define XMotor_h

#include "Arduino.h"

class XMotor {
    private:
        int _speed_pin;
        int _in1_pin;
        int _in2_pin;
    public:
        XMotor(int speed_pin, int in1_pin, int in2_pin);
        void setSpeed(int speed);
        void stop();
        void cw();
        void ccw();
};

#endif