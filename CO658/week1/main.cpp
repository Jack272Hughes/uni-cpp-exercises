#include <iostream>
#include <vector>

using namespace std;

class Entity {
public:
    int size;
    Entity(int size): size(size) {}
};

Entity operator++(Entity& entity) {
    entity.size++;
    return entity;
}

Entity operator--(Entity& entity) {
    entity.size--;
    return entity;
}

bool operator>(Entity& left, Entity& right) {
    return left.size > right.size;
}

bool operator<(Entity& left, Entity& right) {
    return left.size < right.size;
}

class Weapon {
public:
    int id;
    Weapon() {};
    Weapon(int id): id(id) {};
    bool operator==(int id) {
        return this->id == id;
    };
};

class IOObject {
public:
    void DisplayIntLessThan(int n) {
        --n;
        if (n > 0) {
            DisplayIntLessThan(n);
        }
        cout << n << endl;
    }
};

int main() {
    cout << "-=== Exercise 1 ===-" << endl;
    Entity entity1(3);
    Entity entity2(3);

    cout << "entity1 has size " << entity1.size << " before increment and after it has size " << ++entity1.size << endl;
    cout << "entity2 has size " << entity2.size << " before decrement and after it has size " << --entity2.size << endl;

    cout << "Now the result of entity1 > entity2 is equal to " << (entity1 > entity2 ? "true" : "false") << endl;
    cout << "And the result of entity1 < entity2 is equal to " << (entity1 < entity2 ? "true" : "false") << endl;

    cout << "-=== Exercise 2 & 3 ===-" << endl;
    vector<Weapon> weapons;
    for (int id = 0; id < 10; id++) {
        weapons.push_back(Weapon(id));
    }

    cout << "Deleting weapon with id of 5" << endl;
    vector<Weapon>::iterator it;
    it = find(weapons.begin(), weapons.end(), 5);
    weapons.erase(it);

    for (it = weapons.begin(); it != weapons.end(); it++) {
        cout << "Printing out weapon with id " << (*it).id << endl;
    }

    cout << "-=== Exercise 4 ===-" << endl;
    IOObject ioObject;
    // At the beginning of the function it will decrement the passed in arg.
    // It then checks to see if it is greater than zero and if it is, it calls
    // itself with the now decremented value which repeats until it hits zero.
    // It will then print zero to the screen propagating back through the stack
    // which in turn prints out the other numbers in ascending order.
    // Should the cout be above the call to itself then the numbers would instead
    // print out in descending order.
    ioObject.DisplayIntLessThan(20);
}