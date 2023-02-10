#include "Boat.h"
#include <iostream>

Boat::Boat(int id, int damage) : Vehicle(id, damage) { }

void Boat::Display() {
    // Exercise 1
    std::cout << "Boat with id " << id << std::endl;

    // Exercise 2
    // Vehicle::Display();
}
