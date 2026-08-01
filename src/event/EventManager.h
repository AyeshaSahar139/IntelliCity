#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <vector>

#include "../incident/Incident.h"

class EventManager
{
private:
    std::vector<Incident> incidents;

public:
    EventManager();

    void addIncident(const Incident& incident);

    void removeIncident(int incidentId);

    void resolveIncident(int incidentId);

    void displayAllIncidents() const;

    std::vector<Incident> getActiveIncidents() const;
};

#endif