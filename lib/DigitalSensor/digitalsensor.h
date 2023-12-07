#include <Arduino.h>
#include "digitalsensor.h"

DigitalSensor::DigitalSensor(int pin){
    this->pin = pin;
};

DigitalSensor::readDigitalSensor(){
    this->state = digitalRead(pin);
}
