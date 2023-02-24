#include <iostream>
#include "classes/GameObject.h"

using namespace std;

void HelloMessage() {
    cout << "Hello" << endl;
}

void GoodbyeMessage() {
    cout << "Goodbye" << endl;
}

void Message(const string message) {
    cout << message << endl;
}

void Sort(int *numbers, int size, bool (*sortFunction)(int a, int b)) {
    for (int n = 0; n < size; n++) {
        int nBestIndex = n;
        for (int i = n + 1; i < size; i++) {
            if (sortFunction(numbers[i], numbers[nBestIndex])) nBestIndex = i;
        }
        swap(numbers[n], numbers[nBestIndex]);
    }

    for (int i = 0; i < size; i++) cout << numbers[i] << endl;
}

bool Ascending(int a, int b) {
    return a < b;
}

bool Descending(int a, int b) {
    return a > b;
}

int main() {
    cout << "-=== Exercise 1 ===-" << endl;
    void (*helloFunction)() = HelloMessage;
    void (*goodbyeFunction)() = GoodbyeMessage;

    helloFunction();
    goodbyeFunction();

    cout << "-=== Exercise 2 ===-" << endl;
    void (*messageFunction)(const string message) = Message;
    messageFunction("My cool message");

    cout << "-=== Exercise 3 & 4 ===-" << endl;
    int numbers[] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
    Sort(numbers, 9, Ascending);
    Sort(numbers, 9, Descending);

    cout << "-=== Exercise 5 & 6 ===-" << endl;
    GameObject* object = new GameObject(1, 1, 1, 1);
    void (GameObject::*drawFunction)() = &GameObject::Draw;
    (object->*drawFunction)();

    cout << "-=== Exercise 7 ===-" << endl;
    int* (GameObject::*moveFunction)(int x, int y, int z) = &GameObject::Move;
    int* response = (object->*moveFunction)(1, 2, 3);
    for (int i = 0; i < 3; i++) {
        cout << *response << endl;
    }
}