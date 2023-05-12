#include <iostream>
#include "classes/Tree.h"
#include "classes/PlayerTree.h"

using namespace std;

int main() {
    srand(time(0));

    cout << "-=== Exercise 1 & 2 & 3 & 4 ===-" << endl;
    Tree tree = Tree();

    cout << "Inserting values in order: ";
    for (int i = 0; i < 6; i++) {
        int value = (rand() % 100) + 1;
        cout << value << " ";
        tree.Insert(value);
    }
    cout << endl;

    tree.DisplayInOrder(tree.root);

    cout << "-=== Exercise 5 & 6 ===-" << endl;
    PlayerTree playerTree = PlayerTree();
    for (int i = 0; i < 5; i++) {
        int level = (rand() % 5) + 1;
        int kills = (rand() % 20) + 1;
        cout << "Inserting level " << level << " player with " << kills << " kills" << endl;
        playerTree.Insert(level, kills);
    }

    playerTree.DisplayInOrder(playerTree.root);
}
