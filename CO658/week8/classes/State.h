#pragma once
#include "stdafx.h"
#include "LinkedList.h"
#include "Transition.h"

class State {
private:
    CBP callBack;
    Bulb* callBackLocation;
    TStates state;
    LinkedList<Transition>* transitions;
public:
    State* next;
    State(TStates state);
    State(TStates state, CBP callback, Bulb* callbackLocation);

    void AddTransition(State* from, State* to, GP guard, Bulb* guardLocation);
    State* CheckGuards(bool* changed);
    void InvokeCallBack();

    bool operator!=(State& rhd);
    bool operator==(State& rhd);
};
