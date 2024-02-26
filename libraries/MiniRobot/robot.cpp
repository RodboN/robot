#include <Arduino.h>
#include "robot.h"



Robot::Robot() : front(FRONT_PIN), 
                 left(LEFT_PIN),
                 right(RIGHT_PIN),
                 full_left(FULL_LEFT_PIN),
                 full_right(FULL_RIGHT_PIN),
                 left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN_PIN_1, LEFT_MOTOR_IN_PIN_2, LEFT_MOTOR_SPEED_CONST, LEFT_MOTOR_CHANNEL),
                 right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN_PIN_1, RIGHT_MOTOR_IN_PIN_2, RIGHT_MOTOR_SPEED_CONST, RIGHT_MOTOR_CHANNEL),
                 vision(),
                 start(MICRO_START_INPUT_PIN),
                 line_sensorLeft(LINE_SENSOR_LEFT_PIN),
                 line_sensorRight(LINE_SENSOR_RIGHT_PIN),
                 auto_strategy()
{
    this->robot_state = Robot_State::AWAITING_START;
}

void Robot::readSensor(){
    this->line_sensorLeft.readAnalogSensor();
    this->line_sensorRight.readAnalogSensor();
    this->front.readDigitalSensor();
    this->full_left.readDigitalSensor();
    this->left.readDigitalSensor();
    this->full_right.readDigitalSensor();
    this->right.readDigitalSensor();
    
}

void Robot::update(){
    this->start.updateStartState();
    this->readSensor();
    this->vision.updateEnemyPosition(this->front, this->full_left, this->left, this->full_right, this->right, this->line_sensorLeft, this->line_sensorRight);
    switch(this->robot_state){
        case Robot_State::AWAITING_START:
            if(this->start.state == startSate::START){
                this->robot_state =  Robot_State::AUTO_STARTEGY;
            }
            break;
        case Robot_State::AUTO_STARTEGY:
            this->auto_strategy.updateMotors(this->vision, this->left_motor, this->right_motor);
            if(this->start.state == startSate::STOP){
                this->robot_state = Robot_State::STOPPED;
            }
            break;
        case Robot_State::STOPPED:
            this->left_motor.setpower(0);
            this->right_motor.setpower(0);
            break;
        default:
            Serial.println("DEU BAD! =/"); 
    }
}