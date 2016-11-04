#ifndef SmartCar_h
#define SmartCar_h

#include <Arduino.h>
#include <XMotor.h>

class SmartCar {
	private:
	    XMotor _motor1;
	    XMotor _motor2;
  	public:
	    SmartCar(XMotor _motor1, XMotor _motor2);
	    void forward();
	    void backward();
	    void toTheLeft();
	    void toTheRight();
	    void breakCar();
};

#endif