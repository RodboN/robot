#ifndef VISION_H
#define VISION_H

#include "digital_sensor.h"

namespace EnemyPosition{
    enum position{
        FULL_LEFT,
        LEFT,
        FULL_RIGHT,
        RIGHT,
        FRONT,
        SEARCH_LEFT,
        SERACH_RIGHT
    };
}

class Vision{
    public:
        EnemyPosition::position enemy_position, latest_enemy_position;

        Vision();
        void updateEnemyPosition(DigitalSensor &front, DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right);        
};

#endif