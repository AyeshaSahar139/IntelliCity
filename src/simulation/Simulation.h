#ifndef SIMULATION_H
#define SIMULATION_H

#include "../graph/Graph.h"
#include "../vehicle/Vehicle.h"
#include "../incident/Incident.h"
#include "../traffic/TrafficSignal.h"
#include <vector>

class Simulation
{
private:
    Graph* cityGraph;
    int currentStep;
    std::vector<Vehicle> vehicles;
std::vector<Incident> incidents;
std::vector<TrafficSignal> trafficSignals;

public:
void addVehicle(const Vehicle& vehicle);

void addIncident(const Incident& incident);

void addTrafficSignal(const TrafficSignal& signal);
    Simulation();

    Simulation(Graph* graph);

    void runStep();

    void displayStatus() const;

    int getCurrentStep() const;
};

#endif