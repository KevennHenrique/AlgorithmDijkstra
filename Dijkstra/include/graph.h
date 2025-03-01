#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <functional>
#include <stack>

#include "vertex.h"


using namespace std;

class graph{
private:
    int vertices;                               //quantidade de vertices
    vector<vector<pair<int, int>>> adjList;     //lista de adjacencia   //pair(vertice, peso)
    vector<vertex> vertexList;

public:
    graph(int v);
    void addEdgeDirectional(int u, int v, int w);
    void addEdgeNonDirectional(int u, int v, int w);
    void initializeSingleSource(int start);
    void relax(int u, int v, int weight);
    void dijkstra(int start);
    void printShortestDistance();
    void printShortestPaths(int start);

};


#endif // GRAPH_H_INCLUDED
