#pragma once
#include "Graph.h"
#include "PriorityQueue.h"
#include "Location.h"

class BreadthFirstSearch {
private:
    Graph* graph;
    PriorityQueue<Location>* queue;
public:
    BreadthFirstSearch(Graph* graph);

    PriorityQueue<Location>* GetAllAdjacentUnvisited(Location* current);
    void Traverse(Location* start);
};
