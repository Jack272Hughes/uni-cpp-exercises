#pragma once
#include "Location.h"

class GameObject {
public:
	static int instances;
	int id = 0;
	Location* location;

	GameObject(int id, Location* location);
};

