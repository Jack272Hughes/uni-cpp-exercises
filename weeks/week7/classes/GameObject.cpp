#include <iostream>
using namespace std;

template <class T>
class GameObject {
private:
    int id;
    T position[3];
public:
    GameObject(int id, T x, T y, T z) {
        this->id = id;
        this->position[0] = x;
        this->position[1] = y;
        this->position[2] = z;
    };

    void Draw() {
        cout << "Classname: GameObject, Id: " << id << endl; 
    };

    T* Move(T x, T y, T z) {
        position[0] += x;
        position[1] += y;
        position[2] += z;
        return position;
    };
};
