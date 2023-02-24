#include <iostream>

using namespace std;

class NPC{
public:
    int id;
    NPC(){}
    NPC(int id):id(id){}
};

class AIManager{
private:
    NPC **npcs;
    int count;
    int size;
public:
    AIManager(int size) : size(size) {
        assert(size > 0);
        npcs = new NPC*[size];
        count = 0;
    }

    // Destructor created to loop through npcs to delete
    // objects then the dynamic array itself is removed
    ~AIManager() {
        for (int n = 0; n < count; n++) {
            delete npcs[n];
        }
        delete[] npcs;
    }

    int Add(int id) {
        assert(count < size);
        assert(id != 0);
        for (int n = 0; n < count; n++)
            if (npcs[n]->id == id) return 0;
        // This "new NPC" was moved to below the check since before we would
        // return and leave an object on the heap that can no longer be accessed
        NPC *temp = new NPC(id);
        npcs[count++] = temp;
        return id;
    }

    void Display() {
        for (int n = 0; n < count; n++)
            cout << "NPC ID: " << npcs[n]->id << endl;
    }
};

void memoryErrorHandler() {
    cout << "Memory exception occurred!" << endl;
    exit(1);
}

void toYou();
void toMe() {
    return toYou();
}

void toYou() {
    return toMe();
}

int main() {
    AIManager *ai = new AIManager(10);
    ai->Add(1);
    ai->Add(2);
    ai->Add(3);
    ai->Display();

    cout << "-=== Exercise 1 & 2 ===-" << endl;
    delete ai;

    cout << "-=== Exercise 3 ===-" << endl;
    set_new_handler(memoryErrorHandler);
    // while (true) {
    //     char* memoryString = new char[512000];
    // }

    cout << "-=== Exercise 4 ===-" << endl;
    // Both these lines produce a "EXC_BAD_ACCESS (code=2, address=...)"
    // int largeArray[99999999];
    // toYou();

    return 0;
}