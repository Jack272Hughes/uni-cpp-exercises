#include "VehicleManager.h"

VehicleManager::VehicleManager(int size) {
    this->count = 0;
    this->maxVehicles = size;
    this->vehicals = new Vehicle*[size];
}

bool VehicleManager::Add(Vehicle *vehical) {
    if (count >= maxVehicles) return false;

    vehicals[count] = vehical;
    count++;

    return true;
}

void VehicleManager::Display() {
    for (int i = 0; i < count; i++) {
        vehicals[i]->Display();
    }
}

int VehicleManager::GetCount() {
    return count;
}

Vehicle** VehicleManager::GetList() {
    return vehicals;
}
