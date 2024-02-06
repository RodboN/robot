#ifndef STRATEGY_H
#define STRATEGY_H

#include "vision.h"
#include "motorcontrol.h"


class AutoStrategy{
    public:
        int leftMotor_pwr;
        int rightMotor_pwr;

        AutoStrategy::AutoStrategy();
        void updateMotors(Vision &vision, MotorControl &inpin_1, MotorControl &inpin_2);
};

#endif 