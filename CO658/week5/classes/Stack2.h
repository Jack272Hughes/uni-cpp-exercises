#pragma once

template <class T>
class Stack2 {
private:
    int maxSize;
    T* stackData;
    int top;
public:
    Stack2(int size) {
        maxSize = size;
        stackData = new T[size];
        top = -1;
    }

    bool IsEmpty() {
        return top < 0;
    }

    bool IsFull() {
        return top == maxSize - 1;
    }

    T Peek() {
        return stackData[top];
    }

    T Pop() {
        return stackData[top--];
    }

    void Push(T value) {
        stackData[++top] = value;
    }
};
