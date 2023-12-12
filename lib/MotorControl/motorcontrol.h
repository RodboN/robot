#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

struct MotorConfig{
    int inpin_1; 
    int inpin_2; 
    int pwm_pin;
    float speed_const;
    int channel;
    MotorConfig(int pwm_pin, int inpin_1, int inpin_2, float speed_const, int channel); 
};

class MotorControl{
    public: 
        float max_power = 100;
        int power;
        MotorConfig config;

        MotorControl(int pwm_pin, int inpin_1, int inpin_2, float speed_const, int channel);

        void setpower(int power);
};

#endif