#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int data) {
    this->data = data;
    leftChild = 0;
    rightChild = 0;
}

void Node::Display() {
    cout << this->data << endl;
}
