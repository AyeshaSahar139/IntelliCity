#ifndef TRAFFICCONTROLLER_H
#define TRAFFICCONTROLLER_H

#include <vector>

#include "../traffic/TrafficSignal.h"
#include "../incident/Incident.h"
#include "../vehicle/Vehicle.h"

class TrafficController
{
private:
    std::vector<TrafficSignal> signals;

public:
    TrafficController();

    void addTrafficSignal(const TrafficSignal& signal);

    void updateSignals();

    void handleIncident(const Incident& incident);

    void prioritizeEmergencyVehicle(const Vehicle& vehicle);

    void displaySignals() const;
};

#endif