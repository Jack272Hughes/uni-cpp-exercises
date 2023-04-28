#include "LinkedList.h"

LinkedList::LinkedList() {
    first = 0;
}

Link* LinkedList::Delete(int key) {
    Link* current = first;
    Link* previous = first;
    while (current->GetData() != key) {
        if (current->next == 0) return 0;
        previous = current;
        current = current->next;
    }

    if (current == first) first = current->next;
    else previous->next = current->next;
    return current;
}

void LinkedList::Display() {
    Link* current = first;
    while (current != 0) {
        current->Display();
        current = current->next;
    }
}

Link* LinkedList::Find(int key) {
    Link* current = first;
    while (current->GetData() != key) {
        if (current->next == 0) return 0;
        current = current->next;
    }
    return current;
}

void LinkedList::Insert(Link *newLink) {
    newLink->next = first;
    first = newLink;
}

bool LinkedList::IsEmpty() {
    return (first == 0);
}

Link* LinkedList::DeleteFirst() {
    Link* current = first;
    first = first->next;
    return current;
}
