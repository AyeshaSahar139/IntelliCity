#include "MapLoader.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "../graph/Vertex.h"
#include "../graph/Edge.h"

// Constructor
MapLoader::MapLoader()
{
}

// Load Vertices
bool MapLoader::loadVertices(Graph& graph,
                             const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Unable to open vertex file.\n";
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string token;

        int id;
        std::string name;
        double x;
        double y;

        std::getline(ss, token, ',');
        id = std::stoi(token);

        std::getline(ss, name, ',');

        std::getline(ss, token, ',');
        x = std::stod(token);

        std::getline(ss, token, ',');
        y = std::stod(token);

        Vertex vertex(id, name, x, y);

        graph.addVertex(vertex);
    }

    file.close();

    std::cout << "Vertices loaded successfully.\n";

    return true;
}

// Load Edges
bool MapLoader::loadEdges(Graph& graph,
                          const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Unable to open edge file.\n";
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string token;

        int source;
        int destination;
        double distance;
        double traffic;

        std::getline(ss, token, ',');
        source = std::stoi(token);

        std::getline(ss, token, ',');
        destination = std::stoi(token);

        std::getline(ss, token, ',');
        distance = std::stod(token);

        std::getline(ss, token, ',');
        traffic = std::stod(token);

        Edge edge(source,
                  destination,
                  distance,
                  traffic);

        graph.addEdge(edge);
    }

    file.close();

    std::cout << "Edges loaded successfully.\n";

    return true;
}