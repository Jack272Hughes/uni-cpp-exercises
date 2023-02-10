#include "exceptions/NoAmmoException.cpp"
#include "exceptions/MagazineFullException.cpp"
#include "exceptions/JammedException.cpp"

#include <assert.h>
#include <iostream>
using namespace std;

class Weapon {
private:
    int rounds;
    bool jammed;
    NoAmmoException ENoAmmo;
public:
    Weapon(int initialRounds) {
        // Exercise 7
        assert(initialRounds >= 0 && initialRounds <= 10);
        rounds = initialRounds;
        jammed = true;
    }

    void Fire() throw (JammedException, NoAmmoException) {
        if (jammed) throw JammedException(rounds);
        if (rounds < 1) throw ENoAmmo;
        cout << "Weapon Fired\n" << endl;
        rounds--;
    }
    
    void Reload() throw (MagazineFullException) {
        if (rounds >= 10) throw MagazineFullException();
        rounds = 10;
        cout << "Weapon Reloaded \n" << endl;
    }
};