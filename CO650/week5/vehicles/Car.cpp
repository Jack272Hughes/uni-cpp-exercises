#include "Car.h"
#include <iostream>

Car::Car(int id, int damage) : Vehicle(id, damage) { }

void Car::Display() {
    // Exercise 1
    std::cout << "Car with id " << id << std::endl;

    // Exercise 2
    // Vehicle::Display();
}
