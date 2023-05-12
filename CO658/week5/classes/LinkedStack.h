#pragma once
#include "Link.h"

template <class T>
class LinkedStack {
private:
    Link<T>* first;
public:
    LinkedStack() {
        first = 0;
    }

    bool IsEmpty() {
        return first == 0;
    }

    T Peek() {
        return first->GetData();
    }

    T Pop() {
        T data = first->GetData();
        Link<T>* next = first->next;
        delete first;
        first = next;
        return data;
    }

    void Push(T value) {
        Link<T>* link = new Link<T>(value);
        link->next = first;
        first = link;
    }
};
