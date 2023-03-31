#include "Weapon.cpp"

#include <assert.h>
#include <iostream>
using namespace std;

int main() {
    cout << "-=== Exercise 1 & 2 & 4 & 5 ===-" << endl;
    Weapon weapon = Weapon(10);

    try {
        weapon.Fire();
    } catch(NoAmmoException e) {
        cout << "error: " << e.what() << endl;
    } catch(JammedException e) {
        cout << "error: " << e.what() << " with remaining rounds " << e.getRemainingRounds() << endl;
    } catch(...) {
        // Exercise 4
        cout << "Threw exception" << endl;;
    }

    cout << "-=== Exercise 3 ===-" << endl;
    try {
        weapon.Reload();
        weapon.Reload();
    } catch(MagazineFullException e) {
        cout << "error: " << e.what() << endl;
    }
}
