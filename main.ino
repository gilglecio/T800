#include <Thread.h>
#include <ThreadController.h>
#include <Ultrasonic.h>

#include <XMotor.h>
#include <SmartCar.h>

const int POT_PIN = A0;
const int ULTRASON_ECHO_PIN = 12;
const int ULTRASON_TRIGGER_PIN = 11;
const int BUZZER_GND_PIN = A2;
const int BUZZER_VCC_PIN = A5;

int distance;

ThreadController ctrl = ThreadController();
Thread Actuators = Thread();
Thread Sensors = Thread();

XMotor M1(6, 4 ,7);
XMotor M2(5, 2, 3);
SmartCar Car(M1, M2);
Ultrasonic Sensor(ULTRASON_TRIGGER_PIN, ULTRASON_ECHO_PIN);

void actuatorCall() {

    Car.setSpeed(150, 150);
    Car.forward();

    if (distance < 20){
        bip();
        Car.stop();
        Car.backward();
        Car.toTheLeft();
    }
}

void sensorCall() {
    distance = getDistance();
}

void setup () {
    
    pinMode(POT_PIN, INPUT);
    pinMode(ULTRASON_ECHO_PIN, INPUT);
    pinMode(ULTRASON_TRIGGER_PIN, OUTPUT);
    pinMode(BUZZER_VCC_PIN, OUTPUT);
    pinMode(BUZZER_GND_PIN, OUTPUT);

    digitalWrite(BUZZER_GND_PIN, LOW);
    digitalWrite(BUZZER_VCC_PIN, LOW);

    Car.stop();
    
    Sensors.onRun(sensorCall);
    Sensors.setInterval(100);

    Actuators.onRun(actuatorCall);
    Actuators.setInterval(100);

    ctrl.add(&Actuators);
    ctrl.add(&Sensors);
}

int bip() {
    digitalWrite(BUZZER_VCC_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_VCC_PIN, LOW);
}

int getPotValue() {
    return map(analogRead(POT_PIN), 0, 1024, 0, 255);
}

float getDistance() {
    float cmMsec = Sensor.convert(Sensor.timing(), Ultrasonic::CM);
    return cmMsec;
}

void loop () {
    ctrl.run();
}
