#include <iostream>
#include "classes/Stack1.h"
#include "classes/Stack2.h"
#include "classes/LinkedStack.h"

using namespace std;

int main() {
    cout << "-=== Exercise 1 ===-" << endl;
    Stack1 stack = Stack1(4);

    cout << "Elements being inserted in order: ";
    for (int i = 1; i <= 4; i++) {
        stack.Push(i);
        cout << i << " ";
    }

    cout << endl << "Elements being removed in order: ";
    for (int i = 1; i <= 4; i++) {
        int element = stack.Pop();
        cout << element << " ";
    }
    cout << endl;

    cout << "-=== Exercise 2 ===-" << endl;
    Stack2<int> intStack = Stack2<int>(4);
    Stack2<float> floatStack = Stack2<float>(4);

    for (int i = 1; i <= 4; i++) {
        intStack.Push(i);
        floatStack.Push(i + 0.5);
    }

    cout << "Elements added to stack of type int and float" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Next element at the top of the stack is: "
            << intStack.Pop() << " for int stack and "
            << floatStack.Pop() << " for float stack" << endl;
    }

    cout << "-=== Exercise 3 ===-" << endl;
    LinkedStack<int> linkedIntStack = LinkedStack<int>();

    cout << "Adding elements to linked int stack" << endl;
    for (int i = 1; i <= 4; i++) {
        linkedIntStack.Push(i);
    }

    cout << "Elements being removed in order: ";
    for (int i = 1; i <= 4; i++) {
        int element = linkedIntStack.Pop();
        cout << element << " ";
    }
    cout << endl;
}
