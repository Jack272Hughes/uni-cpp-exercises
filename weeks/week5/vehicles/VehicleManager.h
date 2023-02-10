#pragma once
#include "Vehicle.h"

class VehicleManager {
private:
    int count;
    int maxVehicles;
    Vehicle** vehicles;
public:
    VehicleManager(int size);

    bool Add(Vehicle* vehicle);
    void Display();
    int GetCount();
    Vehicle** GetList();
    void DisplayDamagedVehicles();

    friend Vehicle** DamagedVehicles(Vehicle **vehicles,int *size);
};
