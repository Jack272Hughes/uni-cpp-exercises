#include <iostream>
#include "classes/GameObject.h"
#include "classes/HashTable.h"
#include "classes/HashTableStr.h"

using namespace std;

int main() {
    cout << "-=== Exercises prerequisites 1 to 10 ===-" << endl;
    HashTable* table = new HashTable(17);
    table->Insert(new GameObject(10, "Bridge"));
    table->Insert(new GameObject(5, "Player"));
    table->Insert(new GameObject(30, "Tank"));
    table->Insert(new GameObject(16, "AI"));
    table->Display();

    cout << "-=== Exercise 1 ===-" << endl;
    // This will placed at index 0 since index 16 is being used by "AI"
    // This is because the hashtable will increment and mod this number
    // until it finds an empty spot which ends up being the next value of 0 
    table->Insert(new GameObject(16, "Collision"));

    cout << "-=== Exercise 2 ===-" << endl;
    GameObject* tankObject = table->Find(30);
    cout << "Found object with name " << tankObject->name << " for key 30" << endl;

    cout << "-=== Exercise 3 ===-" << endl;
    delete table->Delete(30);
    table->Display();

    cout << "-=== Exercise 3 ===-" << endl;
    HashTableStr* stringTable = new HashTableStr(17);
    stringTable->Insert(new GameObjectStr("Bridge"));
    stringTable->Insert(new GameObjectStr("Player"));
    stringTable->Insert(new GameObjectStr("Tank"));
    stringTable->Insert(new GameObjectStr("AI"));
    stringTable->Display();
}