#pragma once

class Vehicle {
private:
    int damage;
protected:
    int id;

public:
    Vehicle(int id, int damage);

    virtual void Display();

    friend class VehicleManager;
    friend Vehicle** DamagedVehicles(Vehicle **vehicles, int *size);
};
