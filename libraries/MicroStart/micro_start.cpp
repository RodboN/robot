#include <Arduino.h>
#include "micro_start.h"

Start::Start(int input_pin){
    this->input_pin = startSate::STOP;
};

void Start::updateStartState(){
    if(digitalRead(input_pin)){
        this->state = startSate::START;
    }
    else{
        this->state = startSate::STOP;
    }
}