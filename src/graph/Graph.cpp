#include "Graph.h"

#include <iostream>
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>

#include <stdexcept>
#include <queue>
#include <unordered_set>

// Constructor
Graph::Graph()
{

}

// Add Vertex
void Graph::addVertex(const Vertex& vertex)
{
    int id = vertex.getId();

    // Check if vertex already exists
    if (vertices.find(id) != vertices.end())
    {
        std::cout << "Vertex with ID " << id << " already exists.\n";
        return;
    }

    // Add vertex
    vertices[id] = vertex;

    // Create empty adjacency list
    adjacencyList[id] = std::vector<Edge>();

    std::cout << "Vertex \"" << vertex.getName()
              << "\" added successfully.\n";
}
void Graph::displayGraph() const
{
    std::cout << "\n========== IntelliCity Graph ==========\n";

    if (vertices.empty())
    {
        std::cout << "Graph is empty.\n";
        return;
    }

    for (const auto& vertexPair : vertices)
    {
        const Vertex& vertex = vertexPair.second;

        std::cout << "\nVertex ID : " << vertex.getId() << "\n";
        std::cout << "Name      : " << vertex.getName() << "\n";
        std::cout << "Position  : ("
                  << vertex.getX()
                  << ", "
                  << vertex.getY()
                  << ")\n";

        std::cout << "Connected Roads:\n";

        auto it = adjacencyList.find(vertex.getId());

        if (it != adjacencyList.end() && !it->second.empty())
        {
            for (const Edge& edge : it->second)
            {
                std::cout
    << " -> "
    << edge.getDestinationId()
    << " | Distance: "
    << edge.getDistance()
    << " km"
    << " | Traffic: "
    << edge.getTrafficFactor()
    << " | Status: "
    << (edge.getStatus() ? "OPEN" : "CLOSED")
    << "\n";
            }
        }
        else
        {
            std::cout << " No connected roads.\n";
        }
    }

    std::cout << "\n=======================================\n";
}
bool Graph::hasVertex(int id) const
{
    return vertices.find(id) != vertices.end();
}
bool Graph::hasEdge(int sourceId, int destinationId) const
{
    auto it = adjacencyList.find(sourceId);

    if (it == adjacencyList.end())
    {
        return false;
    }

    for (const Edge& edge : it->second)
    {
        if (edge.getDestinationId() == destinationId)
        {
            return true;
        }
    }

    return false;
}
void Graph::addEdge(const Edge& edge)
{
    int source = edge.getSourceId();
    int destination = edge.getDestinationId();

    // Check if source exists
    if (!hasVertex(source))
    {
        std::cout << "Source vertex does not exist.\n";
        return;
    }

    // Check if destination exists
    if (!hasVertex(destination))
    {
        std::cout << "Destination vertex does not exist.\n";
        return;
    }

    // Prevent self-loop
    if (source == destination)
    {
        std::cout << "A vertex cannot connect to itself.\n";
        return;
    }

    // Prevent duplicate edge
    if (hasEdge(source, destination))
    {
        std::cout << "Road already exists.\n";
        return;
    }

    // Add road
    adjacencyList[source].push_back(edge);

    std::cout << "Road added from "
              << vertices[source].getName()
              << " to "
              << vertices[destination].getName()
              << ".\n";
}
void Graph::removeEdge(int sourceId, int destinationId)
{
    // Check if source vertex exists
    if (!hasVertex(sourceId))
    {
        std::cout << "Source vertex does not exist.\n";
        return;
    }

    auto& edges = adjacencyList[sourceId];

    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
        if (it->getDestinationId() == destinationId)
        {
            edges.erase(it);

            std::cout << "Road removed from "
                      << vertices[sourceId].getName()
                      << " to "
                      << vertices[destinationId].getName()
                      << ".\n";

            return;
        }
    }

    std::cout << "Road does not exist.\n";
}
void Graph::closeRoad(int sourceId, int destinationId)
{
    auto& roads = adjacencyList[sourceId];

    for (Edge& edge : roads)
    {
        if (edge.getDestinationId() == destinationId)
        {
            edge.setStatus(false);

            std::cout
                << "Road closed between "
                << vertices[sourceId].getName()
                << " and "
                << vertices[destinationId].getName()
                << ".\n";

            return;
        }
    }

    std::cout << "Road not found.\n";
}
void Graph::openRoad(int sourceId, int destinationId)
{
    auto& roads = adjacencyList[sourceId];

    for (Edge& edge : roads)
    {
        if (edge.getDestinationId() == destinationId)
        {
            edge.setStatus(true);

            std::cout
                << "Road reopened between "
                << vertices[sourceId].getName()
                << " and "
                << vertices[destinationId].getName()
                << ".\n";

            return;
        }
    }

    std::cout << "Road not found.\n";
}
void Graph::removeVertex(int id)
{
    // Check if vertex exists
    if (!hasVertex(id))
    {
        std::cout << "Vertex does not exist.\n";
        return;
    }

    std::string name = vertices[id].getName();

    // Remove all incoming roads
    for (auto& pair : adjacencyList)
    {
        auto& edges = pair.second;

        for (auto it = edges.begin(); it != edges.end(); )
        {
            if (it->getDestinationId() == id)
            {
                it = edges.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    // Remove all outgoing roads
    adjacencyList.erase(id);

    // Remove vertex itself
    vertices.erase(id);

    std::cout << "Vertex \"" << name
              << "\" removed successfully.\n";
}
std::vector<Edge> Graph::getNeighbors(int id) const
{
    auto it = adjacencyList.find(id);

    if (it != adjacencyList.end())
    {
        return it->second;
    }

    return {};
}
Vertex Graph::getVertex(int id) const
{
    auto it = vertices.find(id);

    if (it != vertices.end())
    {
        return it->second;
    }

    throw std::runtime_error("Vertex not found.");
}
void Graph::bfs(int startId) const
{
    if (!hasVertex(startId))
    {
        std::cout << "Starting vertex does not exist.\n";
        return;
    }

    std::queue<int> q;
    std::unordered_set<int> visited;

    visited.insert(startId);
    q.push(startId);

    std::cout << "\n===== BFS Traversal =====\n";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        std::cout << vertices.at(current).getName() << "\n";

        auto it = adjacencyList.find(current);

        if (it != adjacencyList.end())
        {
            for (const Edge& edge : it->second)
            {
                int neighbor = edge.getDestinationId();

                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
}
void Graph::dfsHelper(int current,
                      std::unordered_set<int>& visited) const
{
    visited.insert(current);

    std::cout << vertices.at(current).getName() << "\n";

    auto it = adjacencyList.find(current);

    if (it == adjacencyList.end())
        return;

    for (const Edge& edge : it->second)
    {
        int neighbor = edge.getDestinationId();

        if (visited.find(neighbor) == visited.end())
        {
            dfsHelper(neighbor, visited);
        }
    }
}

void Graph::dfs(int startId) const
{
    if (!hasVertex(startId))
    {
        std::cout << "Starting vertex does not exist.\n";
        return;
    }

    std::unordered_set<int> visited;

    std::cout << "\n===== DFS Traversal =====\n";

    dfsHelper(startId, visited);
}
void Graph::dijkstra(int startId) const
{
    if (!hasVertex(startId))
    {
        std::cout << "Start vertex not found.\n";
        return;
    }

    std::unordered_map<int, double> distance;

    for (const auto& vertex : vertices)
    {
        distance[vertex.first] = std::numeric_limits<double>::infinity();
    }

    distance[startId] = 0.0;

    using Node = std::pair<double, int>;

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>
    > pq;

    pq.push({0.0, startId});

    while (!pq.empty())
    {
        int current = pq.top().second;
        double currentDistance = pq.top().first;
        pq.pop();

        if (currentDistance > distance[current])
            continue;

        for (const Edge& edge : adjacencyList.at(current))
        {
            if (!edge.getStatus())
{
    continue;
}
            int neighbor = edge.getDestinationId();

            double newDistance =
                distance[current] +
                edge.getDistance() * edge.getTrafficFactor();

            if (newDistance < distance[neighbor])
            {
                distance[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
            }
        }
    }

    std::cout << "\n===== Shortest Distance from "
              << vertices.at(startId).getName()
              << " =====\n";

    for (const auto& vertex : vertices)
    {
        std::cout
            << vertices.at(vertex.first).getName()
            << " : ";

        if (distance[vertex.first] ==
            std::numeric_limits<double>::infinity())
        {
            std::cout << "Not Reachable\n";
        }
        else
        {
            std::cout << distance[vertex.first] << " km\n";
        }
    }
}
void Graph::shortestPath(int startId, int destinationId) const
{
    if (!hasVertex(startId) || !hasVertex(destinationId))
    {
        std::cout << "Invalid vertex ID.\n";
        return;
    }

    std::unordered_map<int, double> distance;
    std::unordered_map<int, int> parent;

    for (const auto& vertex : vertices)
    {
        distance[vertex.first] = std::numeric_limits<double>::infinity();
        parent[vertex.first] = -1;
    }

    distance[startId] = 0.0;

    using Node = std::pair<double, int>;

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>
    > pq;

    pq.push({0.0, startId});

    while (!pq.empty())
    {
        int current = pq.top().second;
        double currentDistance = pq.top().first;
        pq.pop();

        if (currentDistance > distance[current])
            continue;

        for (const Edge& edge : adjacencyList.at(current))
        {
            if (!edge.getStatus())
{
    continue;
}
            int neighbor = edge.getDestinationId();

            double newDistance =
                distance[current] +
                edge.getDistance() * edge.getTrafficFactor();

            if (newDistance < distance[neighbor])
            {
                distance[neighbor] = newDistance;
                parent[neighbor] = current;
                pq.push({newDistance, neighbor});
            }
        }
    }

    if (distance[destinationId] == std::numeric_limits<double>::infinity())
    {
        std::cout << "\nNo path found.\n";
        return;
    }

    std::vector<int> path;

    for (int v = destinationId; v != -1; v = parent[v])
    {
        path.push_back(v);
    }

    std::reverse(path.begin(), path.end());

    std::cout << "\n===== Shortest Path =====\n";

    for (size_t i = 0; i < path.size(); i++)
    {
        std::cout << vertices.at(path[i]).getName();

        if (i != path.size() - 1)
            std::cout << " -> ";
    }

    std::cout << "\nTotal Cost : "
              << distance[destinationId]
              << " km\n";
}
