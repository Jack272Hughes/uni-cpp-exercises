#pragma once

template <class T>
class Stack {
private:
    int maxSize;
    T** stackData;
    int top;
public:
    Stack(int maxSize) {
        this->maxSize = maxSize;
        stackData = new T*[maxSize];
        top = -1;
    }

    void Push(T* value)  {
        stackData[++top] = value;
    }

    int Count() {
        return top + 1;
    }

    T* Pop() {
        return stackData[top--];
    }
    
    T* Peek() {
        return stackData[top];
    }
    
    bool IsEmpty() {
        return top == -1;
    }
    
    bool IsFull() {
        return top == (maxSize + 1);
    }
};
