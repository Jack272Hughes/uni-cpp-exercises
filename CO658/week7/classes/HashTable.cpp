#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size) {
    this->size = size;
    this->data = new GameObject*[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = NULL;
    }
}

void HashTable::Display() {
    for (int i = 0; i < size; i++) {
        GameObject* item = this->data[i];
        if (item != NULL) {
            cout << "index: " << i << " key: " << item->key << " name: " << item->name << endl;
        }
    }
}

int HashTable::HashFunction(int key){
    return key % size;
}

void HashTable::Insert(GameObject * item){
    int key = item->key;
    int hash = HashFunction(key);
    while (data[hash] != NULL){
        ++hash;
        hash %= size;
    }
    data[hash] = item;
}

GameObject *HashTable::Find(int key) {
    int hash = HashFunction(key);
    while(data[hash] != NULL) {
        if (data[hash]->key == key) {
            return data[hash];
        }
        hash = ++hash % size;
    }
    return NULL;
}

GameObject *HashTable::Delete(int key) {
    int hash = HashFunction(key);
    while(data[hash] != NULL) {
        if (data[hash]->key == key) {
            GameObject* temp = data[hash];
            data[hash] = NULL;
            return temp;
        }
        hash = ++hash % size;
    }
    
    return nullptr;
}
