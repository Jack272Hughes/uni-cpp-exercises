#pragma once
#include "Vehicle.h"

class Boat : public Vehicle {
public:
    Boat(int id, int damage);

    void Display() override;
};
