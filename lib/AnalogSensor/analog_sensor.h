#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

class AnalogSensor{
    public:
        int pin, interval, state;
        
        AnalogSensor(int pin);

        void readAnalogSensor();
};

#endif