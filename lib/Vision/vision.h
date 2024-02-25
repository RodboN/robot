#ifndef VISION_H
#define VISION_H

#include "digital_sensor.h"
#include "analog_sensor.h"

namespace EnemyPosition{
    enum position{
        FULL_LEFT,
        LEFT,
        FULL_RIGHT,
        RIGHT,
        FRONT,
        SEARCH_LEFT,
        SERACH_RIGHT,
        LINE_LEFT,
        LINE_RIGHT
    };
}


class Vision{
    public:
        EnemyPosition::position enemy_position, latest_enemy_position;

        Vision();
        void updateEnemyPosition(DigitalSensor &front, DigitalSensor &full_left, DigitalSensor &left, DigitalSensor &full_right, DigitalSensor &right, AnalogSensor &line_sensorLeft, AnalogSensor &sensor_lineRight);      
};

#endif