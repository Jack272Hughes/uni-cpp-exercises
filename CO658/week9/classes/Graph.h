#pragma once
#include "Location.h"
#include "PriorityQueue.h"

class Graph {
private:
    const int INF = __INT_MAX__;
    int size;
    int** adjacencyMatrix;
    int totalVertices;
    Location** vertices;
public:
    Graph(int size);

    void AddEdge(int start, int end, int weight);
    void AddVertex(Location* vertex);
    void Display();
    PriorityQueue<Location>* GetAdjacentVertices(Location* vertex);
    int GetTotalVertices(); 
};
