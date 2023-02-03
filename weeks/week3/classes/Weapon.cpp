#include "Weapon.h"

Weapon::Weapon() {
	rounds = 10;
}

bool Weapon::Fire(Person* person) {
	return Fire(person, 1);
}

bool Weapon::Fire(Person* person, int burst) {
	if (rounds - burst < 0) return false;

	string message = "Weapon Fired";
	if (burst > 1) message = "Automatic " + message;
	cout << message << endl;

	rounds -= burst;
	person->Damage(burst);

	return true;
}

void Weapon::Reload() {
	rounds = 10;
	cout << "Reloading" << endl;
}
