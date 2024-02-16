#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

class DigitalSensor{
    public:
        int pin;
        bool state;

        DigitalSensor(int pin);

        void readDigitalSensor();
};

#endif