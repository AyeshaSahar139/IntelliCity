#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include "../graph/Graph.h"
#include "../map/MapLoader.h"
#include "../simulation/Simulation.h"
#include "../event/EventManager.h"
#include "../trafficcontroller/TrafficController.h"

class CityManager
{
private:
    Graph cityGraph;
    MapLoader mapLoader;
    Simulation simulation;
    EventManager eventManager;
    TrafficController trafficController;

public:
    CityManager();

    bool loadCityMap();

    Graph& getGraph();

    Simulation& getSimulation();

    EventManager& getEventManager();

    TrafficController& getTrafficController();

    void displayCity();
};

#endif