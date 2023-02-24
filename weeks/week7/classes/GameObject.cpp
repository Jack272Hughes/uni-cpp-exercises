#include <iostream>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(int id, int x, int y, int z) {
    this->id = id;
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}

void GameObject::Draw() {
    cout << "Classname: GameObject, Id: " << id << endl; 
}

int* GameObject::Move(int x, int y, int z) {
    position[0] += x;
    position[1] += y;
    position[2] += z;
    return position;
}
