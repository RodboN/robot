#include <Arduino.h>
#include "robot.h"
#include "digital_sensor.h"
#include "vision.h"

Robot::Robot();

void Robot::readSensor(){
    this->front.DigitalSensor::readDigitalSensor();
    this->full_left.DigitalSensor::readDigitalSensor();
    this->left.DigitalSensor::readDigitalSensor();
    this->full_right.DigitalSensor::readDigitalSensor();
    this->right.DigitalSensor::readDigitalSensor();

    //aqui deveria entrar ifs para o robot state?
}

void Robot::update(){
    this->vision.Vision::updateEnemyPosition(DigitalSensor &front, DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right);
}