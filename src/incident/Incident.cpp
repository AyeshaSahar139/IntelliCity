#include "Incident.h"

#include <iostream>

// Default Constructor
Incident::Incident()
{
    incidentId = 0;
    sourceId = 0;
    destinationId = 0;
    type = "Unknown";
    severity = "Low";
    active = false;
}

// Parameterized Constructor
Incident::Incident(int incidentId,
                   int sourceId,
                   int destinationId,
                   std::string type,
                   std::string severity)
{
    this->incidentId = incidentId;
    this->sourceId = sourceId;
    this->destinationId = destinationId;
    this->type = type;
    this->severity = severity;
    active = true;
}

// Getters
int Incident::getIncidentId() const
{
    return incidentId;
}

int Incident::getSourceId() const
{
    return sourceId;
}

int Incident::getDestinationId() const
{
    return destinationId;
}

std::string Incident::getType() const
{
    return type;
}

std::string Incident::getSeverity() const
{
    return severity;
}

bool Incident::isActive() const
{
    return active;
}

// Activate Incident
void Incident::activate()
{
    active = true;
}

// Resolve Incident
void Incident::resolve()
{
    active = false;
}

// Display
void Incident::display() const
{
    std::cout << "\n===== Incident =====\n";

    std::cout << "Incident ID : "
              << incidentId << "\n";

    std::cout << "Road : "
              << sourceId
              << " -> "
              << destinationId
              << "\n";

    std::cout << "Type : "
              << type
              << "\n";

    std::cout << "Severity : "
              << severity
              << "\n";

    std::cout << "Status : "
              << (active ? "ACTIVE" : "RESOLVED")
              << "\n";
}