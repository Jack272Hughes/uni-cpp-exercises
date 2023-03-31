#include "Location.h"
#include <iostream>
using namespace std;

Location::Location() {
	Set(0, 0, 0);
}

Location::Location(int x, int y, int z) {
	Set(x, y, z);
}

Location::Location(const Location& location) {
	Set(location.x, location.y, location.z);
}

void Location::Display() {
	cout << "X: " << x << ", Y:" << y << ", Z: " << z << endl;
}

void Location::Set(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
