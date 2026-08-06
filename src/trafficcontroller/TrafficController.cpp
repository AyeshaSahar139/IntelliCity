#include "TrafficController.h"

#include <iostream>

// Constructor
TrafficController::TrafficController()
{
}

// Add Traffic Signal
void TrafficController::addTrafficSignal(const TrafficSignal& signal)
{
    signals.push_back(signal);

    std::cout << "Traffic Signal added.\n";
}

// Update All Signals
void TrafficController::updateSignals()
{
    std::cout << "\nUpdating Traffic Signals...\n";

    for (TrafficSignal &signal : signals)
    {
        signal.nextState();
    }
}

// Handle Incident
void TrafficController::handleIncident(const Incident& incident)
{
    std::cout
        << "\nHandling Incident ID : "
        << incident.getIncidentId()
        << "\n";

    std::cout
        << "Adjusting nearby traffic signals...\n";
}

// Emergency Vehicle Priority
void TrafficController::prioritizeEmergencyVehicle(const Vehicle& vehicle)
{
    if (vehicle.isEmergency())
    {
        std::cout
            << "\nEmergency Vehicle Detected!\n";

        std::cout
            << "Giving GREEN corridor...\n";
    }
    else
    {
        std::cout
            << "\nNormal Vehicle. No priority needed.\n";
    }
}

// Display Signals
void TrafficController::displaySignals() const
{
    std::cout << "\n===== Traffic Signals =====\n";

    if (signals.empty())
    {
        std::cout << "No traffic signals available.\n";
        return;
    }

    for (const TrafficSignal &signal : signals)
    {
        signal.display();
        std::cout << "\n";
    }
}