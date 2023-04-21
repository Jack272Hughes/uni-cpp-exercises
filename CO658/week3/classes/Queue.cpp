#include "Queue.h"

Queue::Queue(int size) {
    this->size = size;
    this->data = new int[size];
    this->front = 0;
    this->back = -1;
    this->count = 0;
}

Queue::~Queue() {
    delete data;
}

void Queue::Insert(int item) {
    back = (back + 1) % size;
    data[back] = item;
    count++;
}

bool Queue::IsEmpty() {
    return count == 0;
}

bool Queue::IsFull() {
    return count == size;
}

int Queue::PeekFront() {
    return data[front];
}

int Queue::Pop() {
    int value = data[front];
    front = (front + 1) % size;
    count--;
    return value;
}

int Queue::Size() {
    return count;
}
