#include <iostream>

#include "classes/Queue.h"
#include "classes/PriorityQueue.h"
#include "classes/PrioQueue.h"
#include "classes/GameObject.h"

using namespace std;

int main() {
    srand(time(0));

    cout << "-=== Exercise 1 & 2 & 3 ===-" << endl;
    int maxSize = 6;
    Queue* queue = new Queue(maxSize);
    for (int i = 1; i <= maxSize; i++) {
        queue->Insert(i);
    }

    cout << "The queue's current size is " << queue->Size() << endl;
    for (int i = 0; i < maxSize; i++) {
        cout << "Next item in the queue is " << queue->Pop() << endl;
    }
    cout << "The queue's current size is now " << queue->Size() << endl;

    cout << "-=== Exercise 4 & 5 ===-" << endl;
    PriorityQueue* priorityQueue = new PriorityQueue(maxSize);
    for (int i = 0; i < maxSize; i++) {
        int value = (rand() % 100) + 1;
        cout << "Adding value " << value << " to the priority queue" << endl;
        priorityQueue->Insert(value);
    }

    for (int i = 0; i < maxSize; i++) {
        cout << "Next item in the priority queue is " << priorityQueue->Pop() << endl;
    }

    cout << "-=== Exercise 6 ===-" << endl;
    PrioQueue<GameObject>* prioQueue = new PrioQueue<GameObject>(maxSize);
    for (int i = 1; i <= maxSize; i++) {
        int key = (rand() % 100) + 1;
        GameObject gameObject = GameObject(key, "Object " + to_string(i));
        cout << "Adding game object with key " << key << " to the prio queue" << endl;
        prioQueue->Insert(gameObject);
    }

    for (int i = 0; i < maxSize; i++) {
        GameObject gameObject = prioQueue->Pop();
        cout << "Next item in the prio queue is object with key " << gameObject.key << " and name " << gameObject.name << endl;
    }
}