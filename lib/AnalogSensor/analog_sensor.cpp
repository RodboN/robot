#include <Arduino.h>
#include "analog_sensor.h"

AnalogSensor::AnalogSensor(int pin){
    this->pin = pin;
};

void AnalogSensor::readAnalogSensor(){
    this->interval = analogRead(this->pin);
    if(interval >= 0 && interval <= 0)
        this->state = 1;
    else
        this->state = 0;
}