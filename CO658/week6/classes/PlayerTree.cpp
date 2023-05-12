#include "PlayerTree.h"

PlayerTree::PlayerTree() {
    root = 0;
}

Player* PlayerTree::Find(int score) {
    Player* current = root;
    while (current->CalculateScore() != score) {
        if (score < current->CalculateScore())
            current = current->leftChild;
        else
            current = current->rightChild;
        if (current == 0)
            return 0;
    }
    return current;
}

void PlayerTree::DisplayInOrder(Player* localRoot) {
    if (localRoot != 0) {
        DisplayInOrder(localRoot->leftChild);
        localRoot->Display();
        DisplayInOrder(localRoot->rightChild);
    }
}

void PlayerTree::Insert(int level, int kills) {
    Player* newPlayer = new Player(level, kills);
    
    if (root == 0) {
        root = newPlayer;
        return;
    }

    Player* current = root;
    Player* parent;
    while (true) {
        parent = current;
        if (Player::LessThan(newPlayer, current)) {
            current = current->leftChild;
            if (current == 0) {
                parent->leftChild = newPlayer;
                return;
            }
        } else {
            current = current->rightChild;
            if (current == 0) {
                parent->rightChild = newPlayer;
                return;
            }
        }
    }
}
