#include "Stack1.h"

Stack1::Stack1(int size) {
    maxSize = size;
    stackData = new int[size];
    top = -1;
}

bool Stack1::IsEmpty() {
    return top < 0;
}

bool Stack1::IsFull() {
    return top == maxSize - 1;
}

int Stack1::Peek() {
    return stackData[top];
}

int Stack1::Pop() {
    return stackData[top--];
}

void Stack1::Push(int value) {
    stackData[++top] = value;
}
