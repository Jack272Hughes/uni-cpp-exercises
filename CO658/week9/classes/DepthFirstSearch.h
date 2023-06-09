#pragma once
#include "Graph.h"
#include "Stack.h"
#include "Location.h"

class DepthFirstSearch {
private:
    Graph* graph;
    Stack<Location>* stack;
public:
    DepthFirstSearch(Graph* graph);

    Location* GetAdjacentUnvisited(Location* current);
    void Traverse(Location* start);
};
