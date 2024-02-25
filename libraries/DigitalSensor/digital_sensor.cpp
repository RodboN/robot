#include <Arduino.h>
#include "digital_sensor.h"

DigitalSensor::DigitalSensor(int pin){
    this->pin = pin;
};

void DigitalSensor::readDigitalSensor(){
    this->state = digitalRead(this->pin);
}
