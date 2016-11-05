#include <Thread.h>
#include <ThreadController.h>
#include <Ultrasonic.h>

#include <XMotor.h>
#include <SmartCar.h>
#include <Buzzer.h>

ThreadController ctrl = ThreadController();

Thread Actuators      = Thread();
Thread Sensors        = Thread();

Ultrasonic Sensor(4, 3);

XMotor M1(10, 9 ,8);
XMotor M2(11, 13, 12);

SmartCar Car(M1, M2);

Buzzer Bip(A4, A1);

int distance;

void actuatorCall() {

    Car.speed(150, 150);
    Car.forward();

    if (distance < 15) {
        Bip.bip();
        Car.backward(300);
        Car.toTheLeft(300);
    }
}

void sensorCall() {
    distance = getDistance();
}

void setup () {

    Car.stop();

    Serial.begin(9600);
    
    Sensors.onRun(sensorCall);
    Sensors.setInterval(50);

    Actuators.onRun(actuatorCall);
    Actuators.setInterval(100);

    ctrl.add(&Actuators);
    ctrl.add(&Sensors);
}

float getDistance() {
    return Sensor.convert(Sensor.timing(), Ultrasonic::CM);
}

void loop () {
    ctrl.run();
}
