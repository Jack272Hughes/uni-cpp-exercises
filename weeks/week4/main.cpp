#include "classes/GameObject.h"
#include "classes/HealthKit.h"
#include <iostream>
using namespace std;

int main() {
    cout << "-=== Exercise 1 & 3 ===-" << endl;
    // GameObject obj1 = GameObject();
    // If the int 'id' is not initialised it will default to 0 due to it being a primitive type
    // cout << "obj1's id is " << obj1.id << endl;

    cout << "-=== Exercise 2 ===-" << endl;
    GameObject obj2 = GameObject(45, new Location(1, 1, 1));
    cout << "obj2's id is " << obj2.id << endl;

    cout << "-=== Exercise 4 ===-" << endl;
    GameObject obj3 = GameObject(3, new Location(2, 2, 2));
    GameObject obj4 = GameObject(4, new Location(3, 3, 3));
    GameObject obj5 = GameObject(5, new Location(4, 4, 4));
    cout << "There are currently " << GameObject::instances << " instances of GameObject" << endl;

    cout << "-=== Exercise 5 ===-" << endl;
    obj2.location->Display();
    obj3.location->Display();
    obj4.location->Display();
    obj5.location->Display();

    cout << "-=== Exercise 6 ===-" << endl;
    GameObject obj6 = obj4;
    obj4.location->Display();
    obj6.location->Display();

    obj4.location->Set(8, 8, 8);
    obj4.location->Display();
    obj6.location->Display();
    // obj6 is a shallow copy of obj4 and therefore they share the same variables and pointers
    obj6 = GameObject(6, new Location(5, 5, 5));

    cout << "-=== Exercise 7 ===-" << endl;
    HealthKit obj7 = HealthKit(7, new Location(6, 6, 6));
    // GameObject's constructor is called before HealthKit's
}
