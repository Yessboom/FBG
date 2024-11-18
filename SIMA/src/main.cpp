#include <Arduino.h>
#include "FSM.h"
#include "FSM_dev.h"
#include "MotorControl.h"
#include "UltrasonicSensor.h"
#include "IRSensor.h"

// IR sensor pins
const int leftIRPin = A0;
const int rightIRPin = A1;

// Ultrasonic sensor pins
const int trigPin = 11;
const int echoPin = 12;

UltrasonicSensor ultrasonicSensor(trigPin, echoPin);
IRSensor leftIRSensor(leftIRPin);
IRSensor rightIRSensor(rightIRPin);
MotorControl motorControl;

FSM fsm(ultrasonicSensor, leftIRSensor, rightIRSensor, motorControl);
FSM_dev fsm_dev(ultrasonicSensor, motorControl);

void setup()
{
    Serial.begin(9600);
    motorControl.init();
    ultrasonicSensor.init();
    leftIRSensor.init();
    rightIRSensor.init();
}

void loop()
{
    //fsm.update();
    fsm_dev.update();
}