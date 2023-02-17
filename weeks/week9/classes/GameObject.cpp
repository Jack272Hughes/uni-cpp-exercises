#include "GameObject.h"
#include <unistd.h>

GameObject::GameObject() {
    health = 100;
}

int GameObject::getHealth() {
    // Sleep added to force unsynced threads to overlap
    usleep(10000);
    return health;
}