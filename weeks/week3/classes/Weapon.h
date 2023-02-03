#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Weapon {
private:
	int rounds;
public:
	Weapon();

	bool Fire(Person* person);
	bool Fire(Person* person, int burst);
	void Reload();
};
