#ifndef SmartCar_h
#define SmartCar_h

#include <Arduino.h>
#include <XMotor.h>

class SmartCar {
	private:
	    XMotor _motor1, _motor2;
  	public:
	    SmartCar(XMotor _motor1, XMotor _motor2);
	    void setSpeed(int speed_m1, int speed_m2);
	    void forward();
	    void backward(int timer);
	    void toTheLeft(int timer);
	    void toTheRight(int timer);
	    void stop();
};

#endif