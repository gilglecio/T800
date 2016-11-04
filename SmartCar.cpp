#include <Arduino.h>
#include <SmartCar.h>

SmartCar::SmartCar(XMotor _motor1, XMotor _motor2): _motor1(_motor1), _motor2(_motor2) {
	_motor1 = _motor1;
	_motor2 = _motor2;
}

void SmartCar::setSpeed(int speed_m1, int speed_m2) {
	_motor1.setSpeed(speed_m1);
	_motor2.setSpeed(speed_m2);
}

void SmartCar::stop() {
	_motor1.stop();
	_motor2.stop();
}

void SmartCar::forward() {
	_motor1.cw();
	_motor2.cw();
}

void SmartCar::backward(int timer) {
	_motor1.ccw();
	_motor2.ccw();
	delay(timer);
}

void SmartCar::toTheLeft(int timer) {
	_motor1.cw();
	_motor2.ccw();
	delay(timer);
}

void SmartCar::toTheRight(int timer) {
	_motor1.ccw();
	_motor2.cw();
	delay(timer);
}