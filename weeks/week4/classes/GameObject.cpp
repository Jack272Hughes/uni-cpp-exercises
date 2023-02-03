#include "GameObject.h"
#include <iostream>
using namespace std;

int GameObject::instances = 0;

GameObject::GameObject(int _id, Location* _location) {
	cout << "GameObject constructor invoked" << endl;
	instances++;
	id = _id;
	location = _location;
}
