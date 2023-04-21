#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size) {
    this->size = size;
    this->data = new int[size];
    this->count = 0;
}

PriorityQueue::~PriorityQueue() {
    delete data;
}

void PriorityQueue::Insert(int item) {
    if (IsEmpty()) {
        data[count++] = item;
        return;
    }

    int i = count - 1;
    for (; i >= 0; i--) {
        if (!(item > data[i])) break;
        data[i + 1] = data[i];
    }
    data[i + 1] = item;
    count++;
}

bool PriorityQueue::IsEmpty() {
    return count == 0;
}

bool PriorityQueue::IsFull() {
    return count == size;
}

int PriorityQueue::PeekMin() {
    return data[count - 1];
}

int PriorityQueue::Pop() {
    return data[--count];
}

int PriorityQueue::Size() {
    return count;
}
