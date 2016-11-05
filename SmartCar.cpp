#include <Arduino.h>
#include <SmartCar.h>

SmartCar::SmartCar(XMotor m1, XMotor m2): _m1(m1), _m2(m2) {
	// ...
}

void SmartCar::speed(int speed_m1, int speed_m2) {
	_m1.speed(speed_m1);
	_m2.speed(speed_m2);
}

void SmartCar::stop() {
	_m1.stop();
	_m2.stop();
}

void SmartCar::forward() {
	_m1.cw();
	_m2.ccw();
}

void SmartCar::backward(int timer) {
	_m1.ccw();
	_m2.cw();
	delay(timer);
}

void SmartCar::toTheLeft(int timer) {
	_m1.cw();
	_m2.cw();
	delay(timer);
}

void SmartCar::toTheRight(int timer) {
	_m1.ccw();
	_m2.ccw();
	delay(timer);
}