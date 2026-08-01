#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class Incident
{
private:
    int incidentId;
    int sourceId;
    int destinationId;
    std::string type;
    std::string severity;
    bool active;

public:
    Incident();

    Incident(int incidentId,
             int sourceId,
             int destinationId,
             std::string type,
             std::string severity);

    int getIncidentId() const;
    int getSourceId() const;
    int getDestinationId() const;

    std::string getType() const;
    std::string getSeverity() const;

    bool isActive() const;

    void activate();
    void resolve();

    void display() const;
};

#endif