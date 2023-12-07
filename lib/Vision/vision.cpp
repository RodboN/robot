#include <Arduino.h>
#include "vision.h"
#include "digitalsensor.h"

Vision::Vision(){
    this-> enemy_position = 0;
    this-> latest_enemy_position = 0;
};

void Vision::updateEnemyPosition(DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right, DigitalSensor &front){
    if(front.state){
        this->enemy_position = EnemyPosition::FRONT;
        this->latest_enemy_position = EnemyPosition::FRONT;
    } else if(full_left.state){
        this->enemy_position = EnemyPosition::FULL_LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
    } else if(left.state){
        this->enemy_position = EnemyPosition::LEFT;
        this->latest_enemy_position = EnemyPosition::LEFT;
    } else if(full_right.state){
        this->enemy_position = EnemyPosition::FULL_RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
    } else if(right.state){
        this->enemy_position = EnemyPosition::RIGHT;
        this->latest_enemy_position = EnemyPosition::RIGHT;
    } else if(latest_enemy_position == EnemyPosition::FULL_LEFT){
        this->enemy_position = EnemyPosition::position::SEARCH_LEFT; 
    } else if(latest_enemy_position == EnemyPosition::FULL_RIGHT){
        this->enemy_position = EnemyPosition::SERACH_RIGHT;
    }
}

