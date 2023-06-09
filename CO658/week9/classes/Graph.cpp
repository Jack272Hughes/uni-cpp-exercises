#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(int size) {
    this->size = size;
    totalVertices = 0;
    vertices = new Location*[size];
    adjacencyMatrix = new int*[size];
    for (int y = 0; y < size; y++) {
        adjacencyMatrix[y] = new int[size];
        for (int x = 0; x < size; x++) {
            adjacencyMatrix[y][x] = INF;
        }
    }
}

void Graph::AddEdge(int start, int end, int weight) {
    adjacencyMatrix[start][end] = weight;
}

void Graph::AddVertex(Location *vertex) {
    vertices[totalVertices++] = vertex;
}

void Graph::Display() {
    cout << "\t";
    for (int index = 0; index < totalVertices; index++) {
        cout << vertices[index]->name << "\t";
    }

    for (int y = 0; y < totalVertices; y++) {
        cout << "\n" << vertices[y]->name << "\t";
        for (int x = 0; x < totalVertices; x++) {
            int value = adjacencyMatrix[y][x];
            cout << (value == INF ? "∞" : to_string(value)) << "\t";
        }
    }

    cout << endl;
}

PriorityQueue<Location> *Graph::GetAdjacentVertices(Location *vertex) {
    PriorityQueue<Location>* adjacent = new PriorityQueue<Location>(totalVertices);
    for (int j = 0; j < totalVertices; j++)
        if (adjacencyMatrix[vertex->key][j] != INF)
            adjacent->Insert(vertices[j]);
    return adjacent;
}

int Graph::GetTotalVertices() {
    return totalVertices;
}
