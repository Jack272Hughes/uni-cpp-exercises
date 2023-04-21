#pragma once

class Queue {
private:
    int count;
    int* data;
    int front;
    int back;
    int size;
public:
    Queue(int size);
    ~Queue();

    void Insert(int item);
    bool IsEmpty();
    bool IsFull();
    int PeekFront();
    int Pop();
    int Size();
};
