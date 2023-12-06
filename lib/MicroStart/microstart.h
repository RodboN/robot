#ifndef MICROSTART_H
#define MICROSTART_H

namespace startSate{
    enum sState{
        STOP,
        START
    };
}

class Start{
    public:
        int inputPin;
        startSate::sState state;

        Start(int inputPin);
        void updateStartState();
        
};

#endif