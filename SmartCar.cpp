#include <Arduino.h>
#include <SmartCar.h>

SmartCar::SmartCar(XMotor _motor1, XMotor _motor2): _motor1(_motor1), _motor2(_motor2) {
	_motor1 = _motor1;
	_motor2 = _motor2;
}

void SmartCar::breakCar() {
	_motor1.breakMotor();
	_motor2.breakMotor();
}

void SmartCar::forward() {
	_motor1.cw();
	_motor2.cw();
}

void SmartCar::backward() {
	_motor1.ccw();
	_motor2.ccw();
}

void SmartCar::toTheLeft() {
	_motor1.cw();
	_motor2.ccw();
}

void SmartCar::toTheRight() {
	_motor1.ccw();
	_motor2.cw();
}