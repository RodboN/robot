#ifndef DIGITALSENSOR_H
#define DIGITALSENSOR_H

class DigitalSensor{
    public:
        int pin;
        bool state;

        DigitalSensor(int pin);

        void readDigitalSensor();
};

#endif