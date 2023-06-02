#pragma once

#include "State.h"
#include "LinkedList.h"

class FSM {
private:
    State* currentState;
    LinkedList<State>* states;
public:
    FSM();
    
    void AddState(State* state);
    void AddTransition(TStates from, TStates to, GP guardFunction, Bulb* guardLocation);
    void Check();
    State* GetCurrentState();
};
