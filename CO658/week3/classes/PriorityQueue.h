#pragma once

class PriorityQueue {
private:
    int count;
    int* data;
    int size;
public:
    PriorityQueue(int size);
    ~PriorityQueue();

    void Insert(int item);
    bool IsEmpty();
    bool IsFull();
    int PeekMin();
    int Pop();
    int Size();
};
