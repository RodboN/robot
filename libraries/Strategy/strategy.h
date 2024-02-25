#ifndef STRATEGY_H
#define STRATEGY_H

#include "vision.h"
#include "motor_control.h"


class AutoStrategy{
    public:

        void updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor);
};

#endif 