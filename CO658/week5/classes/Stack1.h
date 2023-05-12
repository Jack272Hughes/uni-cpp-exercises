#pragma once

class Stack1 {
private:
    int maxSize;
    int* stackData;
    int top;
public:
    Stack1(int size);

    bool IsEmpty();
    bool IsFull();
    int Peek();
    int Pop();
    void Push(int value);
};
