#pragma once
#include "GameObjectStr.h"

class HashTableStr {
private:
    GameObjectStr** data;
    int size;
public:
    HashTableStr(int size);

    void Display();
    int HashFunction(string key);
    void Insert(GameObjectStr* item);
    GameObjectStr* Find(string key);
    GameObjectStr* Delete(string key);
};
