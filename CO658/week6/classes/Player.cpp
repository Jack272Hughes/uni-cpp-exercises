#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(int level, int kills) {
    this->kills = kills;
    this->level = level;
    leftChild = 0;
    rightChild = 0;
}

void Player::Display() {
    cout << "Level: " << this->level << ", Kills: " << this->kills << ", Score: " << CalculateScore() << endl;
}

int Factorial(int n) {
    if (n == 1) return 1;
    return Factorial(n - 1) * n;
}

int Player::CalculateScore() {
    return Factorial(level) * kills;
}

bool Player::LessThan(Player* p1, Player* p2){
    int scoreA = p1->CalculateScore();
    int scoreB = p2->CalculateScore();
    if (scoreA < scoreB)
        return true;
    else
        return false;
}
