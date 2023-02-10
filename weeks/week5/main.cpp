#include <iostream>
#include <vector>

#include "vehicles/Vehicle.h"
#include "vehicles/Boat.h"
#include "vehicles/Car.h"
#include "vehicles/VehicleManager.h"

using namespace std;

Vehicle** DamagedVehicles(Vehicle **vehicles, int size) {
    vector<Vehicle*> damagedVehicles;
    for (int i = 0; i < size; i++) {
        if (vehicles[i]->damage >= 35) {
            damagedVehicles.push_back(vehicles[i]);
        }
    }
    return &damagedVehicles[0];
}

int main() {
    cout << "-=== Exercise 1 & 2 ===-" << endl;
    // Vehicle* V1 = new Vehicle(1, 30);
    // Boat* B1 = new Boat(2, 50);
    // Car* C1 = new Car(3, 40);

    // V1->Display();
    // B1->Display();
    // C1->Display();

    cout << "-=== Exercise 3 & 4 ===-" << endl;
    Vehicle* vehicles[5];

    vehicles[0] = new Car(1, 35);
    vehicles[1] = new Boat(2, 55);
    vehicles[2] = new Vehicle(3, 30);
    vehicles[3] = new Car(4, 25);
    vehicles[4] = new Boat(5, 65);

    for (Vehicle* vehicle : vehicles) {
        vehicle->Display();
    }

    // This would use the parent's Display member due to the parent being used as the array type
    // and the Display function wasn't originally declared with 'virtual'

    cout << "-=== Exercise 5 & 6 ===-" << endl;
    VehicleManager vehicleManager = VehicleManager(10);
    for (Vehicle* vehicle : vehicles) {
        vehicleManager.Add(vehicle);
    }

    vehicleManager.Display();

    cout << "-=== Exercise 7 ===-" << endl;
    Vehicle** damagedVehicles = DamagedVehicles(vehicleManager.GetList(), vehicleManager.GetCount());
    for (int index = 0; damagedVehicles[index]; index++) {
        damagedVehicles[index]->Display();
    }

    cout << "-=== Exercise 8 ===-" << endl;
    vehicleManager.DisplayDamagedVehicles();
}