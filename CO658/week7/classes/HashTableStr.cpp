#include <iostream>
#include "HashTableStr.h"

HashTableStr::HashTableStr(int size) {
    this->size = size;
    this->data = new GameObjectStr*[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = NULL;
    }
}

void HashTableStr::Display() {
    for (int i = 0; i < size; i++) {
        GameObjectStr* item = this->data[i];
        if (item != NULL) {
            cout << "index: " << i << " name: " << item->name << endl;
        }
    }
}

int HashTableStr::HashFunction(string key) {
    int total = 0;
    
    for (char& character : key) {
        total += (int) character;
    }

    return total % size;
}

void HashTableStr::Insert(GameObjectStr * item){
    int hash = HashFunction(item->name);
    while (data[hash] != NULL){
        ++hash;
        hash %= size;
    }
    data[hash] = item;
}

GameObjectStr *HashTableStr::Find(string key) {
    int hash = HashFunction(key);
    while(data[hash] != NULL) {
        if (data[hash]->name == key) {
            return data[hash];
        }
        hash = ++hash % size;
    }
    return NULL;
}

GameObjectStr *HashTableStr::Delete(string key) {
    int hash = HashFunction(key);
    while(data[hash] != NULL) {
        if (data[hash]->name == key) {
            GameObjectStr* temp = data[hash];
            data[hash] = NULL;
            return temp;
        }
        hash = ++hash % size;
    }
    
    return nullptr;
}
