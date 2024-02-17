#include <Arduino.h>
#include "motor_control.h"
#include "vision.h"

AutoStrategy::AutoStrategy();

void updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor){
    if(vision.enemy_position == EnemyPosition::FRONT){
        left_motor.setpower(100);
        right_motor.setpower(100);
        return;
    }else if(vision.enemy_position == EnemyPosition::FULL_LEFT){
        left_motor.setpower(-100);
        right_motor.setpower(100);
        return;
    }else if(vision.enemy_position == EnemyPosition::LEFT){
        left_motor.setpower(-20);
        right_motor.setpower(100);
        return;
    }else if(vision.enemy_position == EnemyPosition::FULL_RIGHT){
        left_motor.setpower(100);
        right_motor.setpower(-100);
        return;
    }else if(vision.enemy_position == EnemyPosition::RIGHT){
        left_motor.setpower(100);
        right_motor.setpower(-20);
        return;
    }else if(vision.enemy_position==EnemyPosition::SEARCH_LEFT){
        left_motor.setpower(10);
        right_motor.setpower(100);
        return;
    }else if(vision.enemy_position == EnemyPosition::SERACH_RIGHT){
        left_motor.setpower(100);
        right_motor.setpower(10);
        return;
    }
}




