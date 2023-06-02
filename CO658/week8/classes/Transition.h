#pragma once

#include "stdafx.h"

class State;

class Transition {
private:
    State* fromState;
    GP guardFunction;
    Bulb* guardLocation;
    State* toState;
public:
    Transition* next;
    Transition(State* from, State* to, GP guardFunction, Bulb* guardLocation);

    bool InvokeGuard();
    State* GetToState();
};
