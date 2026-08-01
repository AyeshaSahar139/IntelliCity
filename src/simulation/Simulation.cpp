#include "Simulation.h"

#include <iostream>

// Default Constructor
Simulation::Simulation()
{
    cityGraph = nullptr;
    currentStep = 0;
}

// Parameterized Constructor
Simulation::Simulation(Graph* graph)
{
    cityGraph = graph;
    currentStep = 0;
}

// Run One Simulation Step
void Simulation::runStep()
{
    currentStep++;

    std::cout << "\n==============================\n";
    std::cout << "Simulation Step : "
              << currentStep
              << "\n";
    std::cout << "==============================\n";
}

// Display Simulation Status
void Simulation::displayStatus() const
{
    std::cout << "\n===== Simulation Status =====\n";

    std::cout << "Current Step : "
              << currentStep
              << "\n";

    if (cityGraph != nullptr)
    {
        std::cout << "Graph Connected : YES\n";
    }
    else
    {
        std::cout << "Graph Connected : NO\n";
    }
}

// Getter
int Simulation::getCurrentStep() const
{
    return currentStep;
}
void Simulation::addVehicle(const Vehicle& vehicle)
{
    vehicles.push_back(vehicle);

    std::cout
        << "Vehicle added to simulation.\n";
}

void Simulation::addIncident(const Incident& incident)
{
    incidents.push_back(incident);

    std::cout
        << "Incident added to simulation.\n";
}

void Simulation::addTrafficSignal(const TrafficSignal& signal)
{
    trafficSignals.push_back(signal);

    std::cout
        << "Traffic Signal added to simulation.\n";
}