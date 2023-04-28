#include <iostream>
#include "Link.h"

using namespace std;

Link::Link(int data) {
    this->data = data;
}

void Link::Display() {
    cout << data << endl;
}

int Link::GetData() {
    return data;
}
