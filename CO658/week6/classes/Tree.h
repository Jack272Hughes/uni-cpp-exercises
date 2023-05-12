#pragma once 
#include "Node.h"

class Tree {
public:
    Node* root;
    Tree();
    Node* Find(int key);
    void DisplayInOrder(Node* localRoot);
    void Insert(int value);
};
