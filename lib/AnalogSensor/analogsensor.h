#include <Arduino.h>
#include "analogsensor.h"

AnalogSensor::AnalogSensor(int pin){
    this->pin = pin;
};

AnalogSensor::readAnalogSensor(){
    this->state = digitalRead(pin);
}
