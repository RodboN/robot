#include <Arduino.h>
#include "analog_sensor.h"

AnalogSensor::AnalogSensor(int pin){
    this->pin = pin;
};

void AnalogSensor::readAnalogSensor(){
    this->read_value = analogRead(this->pin);
    if(read_value >= threshold && read_value <= threshold)
        this->state = 1;
    else
        this->state = 0;
}