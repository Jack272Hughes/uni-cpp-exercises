#include "classes/Bulb.h"

int main() {
    Bulb *bulb = new Bulb();
    bulb->Update();
    bulb->voltage = 0;
    bulb->Update();
    bulb->voltage = 240;
    bulb->Update();
    bulb->voltage = 500;
    bulb->Update();
}
