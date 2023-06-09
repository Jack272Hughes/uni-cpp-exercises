#include <iostream>
#include "classes/Graph.h"
#include "classes/BreadthFirstSearch.h"
#include "classes/DepthFirstSearch.h"

using namespace std;

int main() {
    cout << "-=== Exercise 1 to 3 ===-" << endl;
    int size = 9;
    Graph* graph = new Graph(size);
    
    Location** locations = new Location*[size];
    for (int index = 0; index < size; index++) {
        locations[index] = new Location(index, char(index + 65));
        graph->AddVertex(locations[index]);
    }

    for (int index = 1; index <= 4; index++) graph->AddEdge(0, index, 1);
    graph->AddEdge(1, 5, 1);
    graph->AddEdge(5, 7, 1);
    graph->AddEdge(3, 6, 1);
    graph->AddEdge(6, 8, 1);
    graph->Display();

    cout << "-=== Exercise 4 ===-" << endl;
    BreadthFirstSearch* bfs = new BreadthFirstSearch(graph);
    bfs->Traverse(locations[0]);

    cout << "-=== Exercise 5 ===-" << endl;
    // Reset visited status of all locations
    for (int index = 0; index < size; index++) locations[index]->wasVisited = false;
    DepthFirstSearch* dfs = new DepthFirstSearch(graph);
    dfs->Traverse(locations[0]);
}
