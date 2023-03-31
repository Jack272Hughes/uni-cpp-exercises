#include <iostream>
#include "classes/GameObject.cpp"

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

template <typename T>
void DisplayArray(T array[], int count) {
    for (int i = 0; i < count; i++) {
        cout << array[i] << endl;
    }
}

template <typename T>
T SumArray(T array[], int count) {
    T sum = 0;
    for (int i = 0; i < count; i++) {
        sum += array[i];
    }
    return sum;
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
    GameObject<int>* object = new GameObject<int>(1, 1, 1, 1);
    void (GameObject<int>::*drawFunction)() = &GameObject<int>::Draw;
    (object->*drawFunction)();

    cout << "-=== Exercise 7 ===-" << endl;
    int* (GameObject<int>::*moveFunction)(int x, int y, int z) = &GameObject<int>::Move;
    int* response = (object->*moveFunction)(1, 2, 3);
    for (int i = 0; i < 3; i++) {
        cout << *response << endl;
    }

    cout << "-=== Exercise 8 ===-" << endl;
    float floats[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 };
    DisplayArray(numbers, 9);
    DisplayArray(floats, 9);

    cout << "-=== Exercise 9 ===-" << endl;
    cout << "Count of integers: " << SumArray(numbers, 9) << endl;
    cout << "Count of floats: " << SumArray(floats, 9) << endl;

    cout << "-=== Exercise 10 ===-" << endl;
    GameObject<float>* floatObject = new GameObject<float>(1, 0.1f, 0.1f, 0.1f);
    void (GameObject<float>::*floatDrawFunction)() = &GameObject<float>::Draw;
    float* (GameObject<float>::*floatMoveFunction)(float x, float y, float z) = &GameObject<float>::Move;

    (floatObject->*floatMoveFunction)(0.1, 0.2, 0.3);
    (floatObject->*floatDrawFunction)();
}