#include "VehicleManager.h"

VehicleManager::VehicleManager(int size) {
    this->count = 0;
    this->maxVehicles = size;
    this->vehicles = new Vehicle*[size];
}

bool VehicleManager::Add(Vehicle *vehical) {
    if (count >= maxVehicles) return false;

    vehicles[count] = vehical;
    count++;

    return true;
}

void VehicleManager::Display() {
    for (int i = 0; i < count; i++) {
        vehicles[i]->Display();
    }
}

int VehicleManager::GetCount() {
    return count;
}

Vehicle** VehicleManager::GetList() {
    return vehicles;
}

void VehicleManager::DisplayDamagedVehicles() {
    for (int i = 0; i < count; i++) {
        if (vehicles[i]->damage >= 35) {
            vehicles[i]->Display();
        }
    }
}
