#include <exception>
using namespace std;

class JammedException : public exception {
private:
    int remainingRounds;
public:
    JammedException(int remainingRounds) {
        this->remainingRounds = remainingRounds;
    }

    int getRemainingRounds() {
        return remainingRounds;
    }

    virtual const char* what() const throw() {
        return "Weapon is jammed";
    }
};
