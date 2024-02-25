#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "motor_control.h"

MotorConfig::MotorConfig(int pwm_pin, int in_pin_1, int in_pin_2, float speed_const, int channel){
    this->pwm_pin = pwm_pin;
    this->in_pin_1 = in_pin_1;
    this->in_pin_2 = in_pin_2;
    this->speed_const = speed_const;
    this->channel = channel;
};

//fazendo assim para aprender - poderia ser feito manualmente recebendo config.<variável>
MotorControl::MotorControl(int pwm_pin, int in_pin_1, int in_pin_2, float speed_const, int channel) : config(pwm_pin, in_pin_1, in_pin_2, speed_const, channel){}

void MotorControl::setpower(int power){
    this->power = power;

    //criando a potencia fixada para condicoes
    float fix_power = power * this->config.speed_const;

    //convertendo a potencia para % (0...255)
    int pwn = (int)(this->max_power / (100.0 * 255.0) * ((float)abs(fix_power) / 100.0));

    //enviando pwn para o motor
    if(fix_power < 0 && fix_power <= -220){
        digitalWrite(this->config.in_pin_1, HIGH);
        digitalWrite(this->config.in_pin_2, LOW);
    }else if(fix_power > 0 && fix_power <= 220){
        digitalWrite(this->config.in_pin_1, LOW);
        digitalWrite(this->config.in_pin_2, HIGH);
    }else{
        std::cout << "INVALID POWER!";
        return;
    }

    //enviando pwn para channel
    ledcWrite(this->config.channel, pwn);
}