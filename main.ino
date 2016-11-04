#include <Thread.h>
#include <ThreadController.h>
#include <Ultrasonic.h>

#include <XMotor.h>
#include <SmartCar.h>
#include <Buzzer.h>

ThreadController ctrl = ThreadController();
Thread Actuators      = Thread();
Thread Sensors        = Thread();

Ultrasonic Sensor(11, 12);
XMotor     M1(6, 4 ,7);
XMotor     M2(5, 2, 3);
Buzzer     Bip(A2, A5);
SmartCar   Car(M1, M2);

int distance;

void actuatorCall() {

    Car.setSpeed(150, 150);
    Car.forward();
    
    if(distance < 60){
        Bip.bip();
    }

    if(distance < 40){
        Car.setSpeed(100, 150);
    }

    if (distance < 15) {
        Car.setSpeed(150, 150);
        Car.stop();
        Car.backward(300);
        Car.toTheLeft(300);
    }
}

void sensorCall() {
    distance = getDistance();
}

void setup () {

    Car.stop();
    
    Sensors.onRun(sensorCall);
    Sensors.setInterval(100);

    Actuators.onRun(actuatorCall);
    Actuators.setInterval(100);

    ctrl.add(&Actuators);
    ctrl.add(&Sensors);
}

float getDistance() {
    float cmMsec = Sensor.convert(Sensor.timing(), Ultrasonic::CM);
    return cmMsec;
}

void loop () {
    ctrl.run();
}
