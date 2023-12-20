#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "motorcontrol.h"

MotorConfig::MotorConfig(int pwm_pin, int inpin_1, int inpin_2, float speed_const, int channel){
    this->pwm_pin = pwm_pin;
    this->inpin_1 = inpin_1;
    this->inpin_2 = inpin_2;
    this->speed_const = speed_const;
    this->channel = channel;
};

//fazendo assim para aprender - poderia ser feito manualmente recebendo config.<variável>
MotorControl::MotorControl(int pwm_pin, int inpin_1, int inpin_2, float speed_const, int channel) : config(pwm_pin, inpin_1, inpin_2, speed_const, channel){}

void MotorControl::setpower(int power){
    this->power = power;

    //criando a potencia fixada para condicoes
    float fix_power = power * this->config.speed_const;

    //convertendo a potencia para % (0...255)
    int pwn = (int)(this->max_power / (100.0 * 255.0) * ((float)abs(fix_power) / 100.0));

    //enviando pwn para o motor
    if(fix_power < 0 && fix_power <= -220){
        digitalWrite(this->config.inpin_1, HIGH);
        digitalWrite(this->config.inpin_2, LOW);
    }else if(fix_power > 0 && fix_power <= 220){
        digitalWrite(this->config.inpin_1, LOW);
        digitalWrite(this->config.inpin_2, HIGH);
    }else{
        std::cout << "INVALID POWER!";
        return;
    }

    //enviando pwn para channel
    ledcWrite(this->config.channel, pwn);
}