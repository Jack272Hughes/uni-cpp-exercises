#pragma once
#include "GameObject.h"
#include "Location.h"

class HealthKit : public GameObject {
public:
	HealthKit(int id, Location* location);
};

