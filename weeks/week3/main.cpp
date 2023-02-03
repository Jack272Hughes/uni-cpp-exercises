#include "classes/Soldier.h"

int main()
{
    cout << "-=== Exercise 1 ===-" << endl;
    Person* person = new Person;

    person->Crawl();
    person->Run();
    person->Stand();
    person->Walk();

    cout << "\n-=== Exercises 2 & 3 & 6 ===-" << endl;
    Weapon* weapon = new Weapon;
    Soldier* soldier = new Soldier(weapon);

    soldier->Stand();
    soldier->FireWeapon(person);

    cout << "\n-=== Exercise 4 ===-" << endl;
    soldier->Crawl();
    soldier->FireWeapon(person);

    cout << "\n-=== Exercise 5 & 6 ===-" << endl;
    soldier->Stand();
    soldier->FireWeapon(person, 5);

    delete person;
    delete weapon;
    delete soldier;
}
