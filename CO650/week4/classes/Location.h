#pragma once
class Location {
public:
	int x;
	int y;
	int z;

	Location();
	Location(int x, int y, int z);
	Location(const Location& identifier);

	void Display();
	void Set(int x, int y, int z);
};

