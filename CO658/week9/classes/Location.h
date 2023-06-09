#pragma once

class Location {
private:
    Location* next;
    float x;
    float y;
public:
    int key;
    char name;
    bool wasVisited;
    Location(int key, char name);
    Location(int key, char name, float x, float y);

    void Display();
    bool operator!=(const Location& rhd);
    bool operator==(const Location& rhd);
    bool operator<(const Location& rhd);
    bool operator>(const Location& rhd);
};
