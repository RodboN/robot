#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

class AnalogSensor{
    public:
        int pin, read_value, state, threshold;
        
        AnalogSensor(int pin);

        void readAnalogSensor();
};

#endif