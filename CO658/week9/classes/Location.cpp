#include <iostream>
#include "Location.h"

using namespace std;

Location::Location(int key, char name): Location(key, name, 0, 0) {}

Location::Location(int key, char name, float x, float y) {
    this->key = key;
    this->name = name;
    this->x = x;
    this->y = y;
}

void Location::Display() {
    cout << name << endl;
}

bool Location::operator!=(const Location& rhd) {
    return key != rhd.key;
}

bool Location::operator==(const Location& rhd) {
    return key == rhd.key;
}

bool Location::operator<(const Location& rhd) {
    return key < rhd.key;
}

bool Location::operator>(const Location& rhd) {
    return key > rhd.key;
}

