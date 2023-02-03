#pragma once
#include <iostream>

using namespace std;

class Person {
protected:
	enum Stance { crawl, run, stand, walk };

	Stance stance = walk;
	int health = 100;
public:
	Person();

	void Crawl();
	void Run();
	void Stand();
	void Walk();
	void Damage(int level);
};
