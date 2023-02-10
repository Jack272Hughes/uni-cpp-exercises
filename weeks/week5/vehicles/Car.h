#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int id, int damage);

    void Display() override;
};