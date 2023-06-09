#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(Graph* graph) {
    this->graph = graph;
    stack = new Stack<Location>(graph->GetTotalVertices());
}

Location* DepthFirstSearch::GetAdjacentUnvisited(Location* current) {
    PriorityQueue<Location>* adjacentVerticies = graph->GetAdjacentVertices(current);
    while (!adjacentVerticies->IsEmpty()) {
        Location* adjacentVertex = adjacentVerticies->Remove();
        if (!adjacentVertex->wasVisited) {
            return adjacentVertex;
        }
    }
    return 0;
}

void DepthFirstSearch::Traverse(Location* start) {
    start->wasVisited = true;
    start->Display();
    stack->Push(start);
    while (!stack->IsEmpty()) {
        Location* adjacentVertex = GetAdjacentUnvisited(stack->Peek());
        if (adjacentVertex == 0) stack->Pop();
        else {
            adjacentVertex->wasVisited = true;
            adjacentVertex->Display();
            stack->Push(adjacentVertex);
        }
    }
}
