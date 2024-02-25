#include <Arduino.h>
#include "vision.h"
#include "digital_sensor.h"
#include "analog_sensor.h"
#include "motor_control.h"

Vision::Vision(){
    this-> enemy_position = EnemyPosition::FRONT;
    this-> latest_enemy_position = EnemyPosition::FRONT;
};

void Vision::updateEnemyPosition(DigitalSensor &front, DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right, AnalogSensor &line_sensorLeft, AnalogSensor &line_sensorRight){
    
    if(line_sensorLeft.state ){
        this->enemy_position = EnemyPosition::LINE_LEFT;
        return;
    } else if (line_sensorRight.state){
        this->enemy_position = EnemyPosition::LINE_RIGHT;
        return;
    }else if(front.state){
        this->enemy_position = EnemyPosition::FRONT;
        this->latest_enemy_position = EnemyPosition::FRONT;
        return;
    } else if(full_left.state){
        this->enemy_position = EnemyPosition::FULL_LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
        return;
    } else if(left.state){
        this->enemy_position = EnemyPosition::LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
        return;
    } else if(full_right.state){
        this->enemy_position = EnemyPosition::FULL_RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    } else if(right.state){
        this->enemy_position = EnemyPosition::RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
        return;
    } else if(latest_enemy_position == EnemyPosition::FULL_LEFT){
        this->enemy_position = EnemyPosition::position::SEARCH_LEFT;
        return;
    } else if(latest_enemy_position == EnemyPosition::FULL_RIGHT){
        this->enemy_position = EnemyPosition::SERACH_RIGHT;
        return;
    }
}
