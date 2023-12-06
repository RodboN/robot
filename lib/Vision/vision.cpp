#include <Arduino.h>
#include "vision.h"
#include "digitalsensor.h"

Vision::Vision(){
    this-> enemy_position = 0;
    this-> latest_enemy_positio = 0;
};

void Vision::updateEnemyPosition(DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right, DigitalSensor &front){
    if(full_left){
        this->enemy_position = EnemyPosition::position::FULL_LEFT;
        //this->lateste_enemy_position = enemy_position;
    } else if(left){
        this->enemy_position = EnemyPosition::position::LEFT;
        //this->lateste_enemy_position = enemy_position;
    } else if(full_right){
        this->enemy_position = EnemyPosition::position::FULL_RIGHT;
        //this->lateste_enemy_position = enemy_position;
    } else if(right){
        this->enemy_position = EnemyPosition::position::RIGHT;
        //this->lateste_enemy_position = enemy_position;
    } else if(front){
        this->enemy_position = EnemyPosition::position::FRONT;
        //this->lateste_enemy_position = enemy_position;
     /*} else{
        this-> enemy_position = EnemyPosition::position::FORNT; //aqui e uma duvida, ha um caso emq ue nao retorne algum desses valores, se sim, ai no caso imaginei de armazenar o valor da frente como posicao padrao, esta certo?
    }*/
    this-> latest_enemy_position = enemy_position; //aqui armazeno o valor da ultima posicao do inimigo;
}

