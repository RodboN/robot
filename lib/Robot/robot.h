#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "micro_start.h"
#include "digital_sensor.h"
#include "motor_control.h"
#include "vision.h"
#include "strategy.h"

#define FRONT_SENSOR_PIN 26
#define FULL_RIGHT_SENSOR_PIN 25
#define FULL_LEFT_SENSOR_PIN 13
#define LEFT_SENSOR_PIN 35
#define RIGHT_SENSOR_PIN 34

#define RIGHT_MOTOR_PWM_PIN 4
#define RIGHT_MOTOR_IN1_PIN 16
#define RIGHT_MOTOR_IN2_PIN 17
#define RIGHT_MOTOR_SPEED_CONST 1.0
#define RIGHT_MOTOR_CHANNEL 0

#define LEFT_MOTOR_PWM_PIN 21
#define LEFT_MOTOR_IN1_PIN 18
#define LEFT_MOTOR_IN2_PIN 19
#define LEFT_MOTOR_SPEED_CONST 1.0
#define RIGHT_MOTOR_CHANNEL 1

#define MICRO_START_SIGNAL_PIN 2

/*
PINOS DEPP SWICTH
#define STRATEGY_PIN_A 22
#define STRATEGY_PIN_B 23
#define STRATEGY_PIN_C 14
*/

#define STDBY 5

namespace Robot_State{
    enum States{
        AWAITING_START,
        INITIAL_STRATEGY,
        AUTO_STARTEGY,
        STOPPED
    };
}

class Robot{
    public:
        std::string name = "robot";
        int led_pin = 13;
        Robot_State::States robot_state;
        Start start;
        DigitalSensor front;
        DigitalSensor full_left;
        DigitalSensor left;
        DigitalSensor full_right;
        DigitalSensor right;
        MotorControl left_motor;
        MotorControl rigth_motor;
        Vision vision;
        //InitialStrategy* initial_strategy;
        AutoStrategy auto_strategy;

        void readSensor();
        void update();

        Robot();

};

#endif