#include "Person.h"

Person::Person() {
}

void Person::Crawl() {
	cout << "Crawling" << endl;
	stance = crawl;
}

void Person::Run() {
	cout << "Running" << endl;
	stance = run;
}

void Person::Stand() {
	cout << "Standing" << endl;
	stance = stand;
}

void Person::Walk() {
	cout << "Walking" << endl;
	stance = walk;
}

void Person::Damage(int level) {
	health -= level;
	cout << "Damaged - Remaining Health: " << health << endl;
}
