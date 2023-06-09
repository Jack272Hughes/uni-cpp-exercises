#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch(Graph* graph) {
    this->graph = graph;
    this->queue = new PriorityQueue<Location>(graph->GetTotalVertices());
}

PriorityQueue<Location>* BreadthFirstSearch::GetAllAdjacentUnvisited(Location *current) {
    PriorityQueue<Location>* unvisited = new PriorityQueue<Location>(graph->GetTotalVertices());
    PriorityQueue<Location>* adjacentVerticies = graph->GetAdjacentVertices(current);
    while (!adjacentVerticies->IsEmpty()) {
        Location* adjacentVertex = adjacentVerticies->Remove();
        if (!adjacentVertex->wasVisited) {
            unvisited->Insert(adjacentVertex);
        }
    }
    return unvisited;
}

void BreadthFirstSearch::Traverse(Location* start) {
    start->wasVisited = true;
    queue->Insert(start);
    start->Display();
    while (!queue->IsEmpty()) {
        Location* currentVertex = queue->Remove();
        PriorityQueue<Location>* adjacentVertexQueue = GetAllAdjacentUnvisited(currentVertex);
        while(!adjacentVertexQueue->IsEmpty()) {
            Location* adjacentVertex = adjacentVertexQueue->Remove();
            adjacentVertex->wasVisited = true;
            adjacentVertex->Display();
            queue->Insert(adjacentVertex);
        }
    }
}
