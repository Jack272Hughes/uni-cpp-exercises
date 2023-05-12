#pragma once 
#include "Player.h"

class PlayerTree {
public:
    Player* root;
    PlayerTree();
    Player* Find(int score);
    void DisplayInOrder(Player* localRoot);
    void Insert(int level, int kills);
};
