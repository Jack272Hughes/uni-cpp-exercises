#include "GameObject.h"
#include <iostream>
using namespace std;

int GameObject::instances = 0;

GameObject::GameObject(int id, Location* location) {
	cout << "GameObject constructor invoked" << endl;
	instances++;
	this->id = id;
	this->location = location;
}

GameObject::GameObject(const GameObject &identifier) : GameObject(identifier.id, new Location(*identifier.location)) {
	cout << "GameObject copy constructor invoked" << endl;
}
