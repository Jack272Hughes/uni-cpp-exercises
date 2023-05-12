#pragma once
#include "Link.h"

class LinkedList {
private:
    Link* first;
public:
    LinkedList();

    Link* Delete(int key);
    void Display();
    Link* Find(int key);
    void Insert(Link* newLink);
    bool IsEmpty();
    Link* DeleteFirst();
};
