#pragma once

class Node {
public:
    Node* leftChild;
    Node* rightChild;
    int data;
    Node(int data);
    void Display();
};
