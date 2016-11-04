#include <Ultrasonic.h>
#include <XMotor.h>
#include <SmartCar.h>

const int ULTRASON_ECHO = 12;
const int ULTRASON_TRIGGER = 11;

XMotor M1(6, 4 ,7);
XMotor M2(5, 2, 3);

SmartCar SmartCar(M1, M2);

Ultrasonic Sensor(ULTRASON_TRIGGER, ULTRASON_ECHO);

void setup () {
  
    pinMode(ULTRASON_ECHO, INPUT);
    pinMode(ULTRASON_TRIGGER, OUTPUT);
  
    SmartCar.breakCar();
}

float getDistance() {
    float cmMsec = Sensor.convert(Sensor.timing(), Ultrasonic::CM);
    return cmMsec;
}

void loop () {

    SmartCar.forward();

    if (getDistance() < 20){
        SmartCar.breakCar();
        SmartCar.backward();
        SmartCar.toTheLeft();
    }
}
