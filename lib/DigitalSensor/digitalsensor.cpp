#include <Arduino.h>
#include "digitalsensor.h"

DigitalSensor::DigitalSensor(int pin){
    this->pin = pin;
};

void DigitalSensor::readDigitalSensor(){
    this->state = digitalRead(this->pin);
}
