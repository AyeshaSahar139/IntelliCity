#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
private:
    int vehicleId;
    std::string type;
    int currentLocation;
    int destination;
    double speed;
    bool emergency;

public:
    Vehicle();

    Vehicle(int vehicleId,
            std::string type,
            int currentLocation,
            int destination,
            double speed,
            bool emergency);

    int getVehicleId() const;
    std::string getType() const;
    int getCurrentLocation() const;
    int getDestination() const;
    double getSpeed() const;
    bool isEmergency() const;

    void setCurrentLocation(int location);
    void setDestination(int destination);

    void display() const;
};

#endif