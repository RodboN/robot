#include <Arduino.h>
#include "microstart.h"

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