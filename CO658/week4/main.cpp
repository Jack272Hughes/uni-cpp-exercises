#include <iostream>
#include "classes/LinkedList.h"

using namespace std;

void printIfLinkNotFound(Link* link) {
    if (link == 0) {
        cout << "Unable to find link in list" << endl;
    }
}

int main() {
    cout << "-=== Exercise 1 & 2 ===-" << endl;
    LinkedList* list = new LinkedList();
    for (int i = 1; i <= 6; i++) {
        Link* link = new Link(i);
        list->Insert(link);
    }
    list->Display();

    cout << "-=== Exercise 3 & 4 ===-" << endl;
    Link* foundLink = list->Find(3);
    cout << "Found link with data: " << foundLink->GetData() << endl;
    foundLink = list->Find(7);
    printIfLinkNotFound(foundLink);

    cout << "-=== Exercise 5 & 6 ===-" << endl;
    Link* deletedLink = list->Delete(3);
    cout << "Deleted link with data: " << deletedLink->GetData() << endl;
    deletedLink = list->Delete(7);
    printIfLinkNotFound(deletedLink);

    cout << "-=== Exercise 7 ===-" << endl;
    Link* firstLink = list->DeleteFirst();
    cout << "Deleted first link with data: " << firstLink->GetData() << endl;
    list->Display();
}