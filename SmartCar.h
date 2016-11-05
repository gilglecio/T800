#ifndef SmartCar_h
#define SmartCar_h

#include <Arduino.h>
#include <XMotor.h>

class SmartCar {
	private:
	    XMotor _m1, _m2;
  	public:
	    SmartCar(XMotor m1, XMotor m2);
	    void speed(int speed_m1, int speed_m2);
	    void forward();
	    void backward(int timer);
	    void toTheLeft(int timer);
	    void toTheRight(int timer);
	    void stop();
};

#endif