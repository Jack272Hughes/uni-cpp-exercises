#include "HealthKit.h"
#include <iostream>
using namespace std;

HealthKit::HealthKit(int id, Location* location) : GameObject(id, location) {
	cout << "HealthKit constructor invoked" << endl;
}
