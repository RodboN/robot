#include <Arduino.h>
#include "micro_start.h"

Start::Start(int inputPin){
    this->inputPin = startSate::STOP;
};

void Start::updateStartState(){
    if(digitalRead(inputPin)){
        this->state = startSate::START;
    }
    else{
        this->state = startSate::STOP;
    }
}