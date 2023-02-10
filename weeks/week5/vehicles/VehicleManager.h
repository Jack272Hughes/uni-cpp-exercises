#pragma once
#include "Vehicle.h"

class VehicleManager {
private:
    int count;
    int maxVehicles;
    Vehicle** vehicals;
public:
    VehicleManager(int size);

    bool Add(Vehicle* vehical);
    void Display();
    int GetCount();
    Vehicle** GetList();

    friend Vehicle** DamagedVehicles(Vehicle **vehicles,int *size);
};
