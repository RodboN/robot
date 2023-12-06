#include <Arduino.h>
#include "microstart.h"

Start::Start(int inputPin){
    this->inputPin = inputPin;
};

void Start::updateStartState(){
    if(digitalRead(inputPin) == 1){
        this->state = startSate::sState::START;
    }
    else if(!digitalRead(inputPin) == 0){
        this->state = startSate::sState::STOP;
    }
}