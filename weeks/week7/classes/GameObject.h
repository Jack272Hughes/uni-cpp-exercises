#pragma once

class GameObject {
private:
    int id;
    int position[3];
public:
    GameObject(int id, int x, int y, int z);
    void Draw();
    int* Move(int x, int y, int z);
};
