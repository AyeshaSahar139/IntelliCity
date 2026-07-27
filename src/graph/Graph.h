#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

class Graph
{
private:

    // Stores all vertices using their ID
    std::unordered_map<int, Vertex> vertices;

    // Adjacency List
    std::unordered_map<int, std::vector<Edge>> adjacencyList;

public:

    Graph();

    // Vertex Operations
    void addVertex(const Vertex& vertex);
    void removeVertex(int id);
    bool hasVertex(int id) const;

    // Edge Operations
   // Edge Operations
void addEdge(const Edge& edge);
void removeEdge(int sourceId, int destinationId);

bool hasEdge(int sourceId, int destinationId) const;

void closeRoad(int sourceId, int destinationId);
void openRoad(int sourceId, int destinationId);

void updateTraffic(int sourceId,
                   int destinationId,
                   double newTrafficFactor);

double calculateTravelCost(const Edge& edge) const;
double estimateTravelTime(const Edge& edge) const;

    // Utility
    void displayGraph() const;

    // BFS
    void bfs(int startId) const;

    void dfs(int startId) const;
    void dijkstra(int startId) const;
    void shortestPath(int startId, int destinationId) const;
    

void dfsHelper(int current,
               std::unordered_set<int>& visited) const;

    Vertex getVertex(int id) const;

    std::vector<Edge> getNeighbors(int id) const;
};

#endif