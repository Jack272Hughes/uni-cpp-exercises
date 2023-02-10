#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int id, int damage) {
    this->id = id;
    this->damage = damage;
}

void Vehicle::Display() {
    std::cout << "Vehicle with id " << id << std::endl;
}
