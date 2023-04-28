#pragma once

class Link {
private:
    int data;
public:
    Link* next;
    Link(int data);
    ~Link();

    void Display();
    int GetData();
};
