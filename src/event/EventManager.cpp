#include "EventManager.h"

#include <iostream>

// Constructor
EventManager::EventManager()
{
}

// Add Event
void EventManager::addIncident(const Incident& incident)
{
    incidents.push_back(incident);

    std::cout
        << "Incident added successfully.\n";
}

// Display All Events
void EventManager::displayAllIncidents() const
{
    std::cout << "\n===== Incident List =====\n";

    if (incidents.empty())
    {
        std::cout << "No incidents available.\n";
        return;
    }

    for (const Incident& incident : incidents)
    {
        incident.display();
        std::cout << "\n";
    }
}