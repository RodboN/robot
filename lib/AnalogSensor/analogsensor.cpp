#ifndef ANALOGSENSOR_H
#define ANALOGSENDOR_H

class AnalogSensor{
    public:
        int pin;
        bool state;

        AnalogSensor(int pin);

        void readAnalogSensor();
};

#endif