#pragma once

#include "FSM.h"

class Bulb {
private:
    FSM* fsm;
public:
    int voltage;
    Bulb();

    bool GuardOffToBroken();
    bool GuardOffToOn();
    bool GuardOnToBroken();
    bool GuardOnToOff();
    void OnBroken();
    void OnOff();
    void OnOn();
    void Update();
};
