#include "Soldier.h"

Soldier::Soldier(Weapon* weapon) {
	this->weapon = weapon;
}

void Soldier::FireWeapon(Person* person) {
	FireWeapon(person, 1);
}

void Soldier::FireWeapon(Person* person, int burst) {
	if (stance == crawl) {
		cout << "Unable to fire weapon whilst crawling" << endl;
		return;
	}

	if (weapon != 0) {
		cout << "Firing Weapon" << endl;
		weapon->Fire(person, burst);
	}
}
