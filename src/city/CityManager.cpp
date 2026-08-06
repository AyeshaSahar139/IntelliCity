#include "CityManager.h"

#include <iostream>

// Constructor
CityManager::CityManager()
{
    simulation = Simulation(&cityGraph);
}

// Load Map
bool CityManager::loadCityMap()
{
    bool verticesLoaded =
        mapLoader.loadVertices(cityGraph, "data/vertices.txt");

    bool edgesLoaded =
        mapLoader.loadEdges(cityGraph, "data/edges.txt");

    return verticesLoaded && edgesLoaded;
}

// Graph Getter
Graph& CityManager::getGraph()
{
    return cityGraph;
}

// Simulation Getter
Simulation& CityManager::getSimulation()
{
    return simulation;
}

// Event Manager Getter
EventManager& CityManager::getEventManager()
{
    return eventManager;
}

// Traffic Controller Getter
TrafficController& CityManager::getTrafficController()
{
    return trafficController;
}

// Display Graph
void CityManager::displayCity()
{
    cityGraph.displayGraph();
}