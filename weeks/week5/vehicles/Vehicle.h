#pragma once

class Vehicle {
public:
    int damage;
    int id;

    Vehicle(int id, int damage);

    virtual void Display();
};
