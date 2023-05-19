#pragma once
#include "GameObject.h"

class HashTable {
private:
    GameObject** data;
    int size;
public:
    HashTable(int size);

    void Display();
    int HashFunction(int key);
    void Insert(GameObject* item);
    GameObject* Find(int key);
    GameObject* Delete(int key);
};
