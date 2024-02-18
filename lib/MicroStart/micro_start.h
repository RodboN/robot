#ifndef MICRO_START_H
#define MICRO_START_H

namespace startSate{
    enum sState{
        STOP,
        START
    };
}

class Start{
    public:
        int input_pin;
        startSate::sState state;

        Start(int input_pin);
        void updateStartState();
        
};

#endif