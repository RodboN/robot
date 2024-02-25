#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "micro_start.h"
#include "digital_sensor.h"
#include "motor_control.h"
#include "vision.h"
#include "strategy.h"
#include "analog_sensor.h"

/*
modificadas nomes finais das variaveis de SENSOR_PIN para _PIN
modificadas nomes finais das variaveis de IN1_PIN para _IN_PIN_1/2
modificadas nomes finais das variaveis de SIGNAL_PIN para _INPUT_PIN
*/

#define FRONT_PIN 26
#define FULL_RIGHT_PIN 25
#define FULL_LEFT_PIN 13
#define LEFT_PIN 35
#define RIGHT_PIN 34

#define RIGHT_MOTOR_PWM_PIN 4
#define RIGHT_MOTOR_IN_PIN_1 16
#define RIGHT_MOTOR_IN_PIN_2 17
#define RIGHT_MOTOR_SPEED_CONST 1.0
#define RIGHT_MOTOR_CHANNEL 0

#define LEFT_MOTOR_PWM_PIN 21
#define LEFT_MOTOR_IN_PIN_1 18 
#define LEFT_MOTOR_IN_PIN_2 19
#define LEFT_MOTOR_SPEED_CONST 1.0
#define LEFT_MOTOR_CHANNEL 1

#define MICRO_START_INPUT_PIN 2

#define LINE_SENSOR_LEFT_PIN 30
#define LINE_SENSOR_RIGHT_PIN 31

#define STRATEGY_PIN_A 22
#define STRATEGY_PIN_B 23
#define STRATEGY_PIN_C 14


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
        //int led_pin = 13;
        Robot_State::States robot_state;
        Start start;
        DigitalSensor front;
        DigitalSensor full_left;
        DigitalSensor left;
        DigitalSensor full_right;
        DigitalSensor right;
        AnalogSensor  line_sensorLeft, line_sensorRight;
        MotorControl left_motor;
        MotorControl rigth_motor;
        Vision vision;
        //InitialStrategy* initial_strategy;
        AutoStrategy* auto_strategy();

        void readSensor();
        void update();

        Robot();

};

#endif