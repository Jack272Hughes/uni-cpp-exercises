#include "Location.h"
#include <iostream>
using namespace std;

Location::Location() {
	Set(0, 0, 0);
}

Location::Location(int _x, int _y, int _z) {
	Set(_x, _y, _z);
}

void Location::Display() {
	cout << "X: " << x << ", Y:" << y << ", Z: " << z << endl;
}

void Location::Set(int _x, int _y, int _z) {
	x = _x;
	y = _y;
	z = _z;
}
