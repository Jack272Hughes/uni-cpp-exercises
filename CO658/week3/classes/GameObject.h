#pragma once
#include <string>

using namespace std;

class GameObject {
public:
    int key;
    string name;

    GameObject() {};

    GameObject(int key, string name) {
        this->key = key;
        this->name = name;
    };
    
    bool operator>(const GameObject& gameObject) {
        return this->key > gameObject.key;
    }
};
