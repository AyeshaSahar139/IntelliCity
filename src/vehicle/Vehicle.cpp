#include "Vehicle.h"

#include <iostream>

// Default Constructor
Vehicle::Vehicle()
{
    vehicleId = 0;
    type = "Unknown";
    currentLocation = 0;
    destination = 0;
    speed = 0.0;
    emergency = false;
}

// Parameterized Constructor
Vehicle::Vehicle(int vehicleId,
                 std::string type,
                 int currentLocation,
                 int destination,
                 double speed,
                 bool emergency)
{
    this->vehicleId = vehicleId;
    this->type = type;
    this->currentLocation = currentLocation;
    this->destination = destination;
    this->speed = speed;
    this->emergency = emergency;
}

// Getters
int Vehicle::getVehicleId() const
{
    return vehicleId;
}

std::string Vehicle::getType() const
{
    return type;
}

int Vehicle::getCurrentLocation() const
{
    return currentLocation;
}

int Vehicle::getDestination() const
{
    return destination;
}

double Vehicle::getSpeed() const
{
    return speed;
}

bool Vehicle::isEmergency() const
{
    return emergency;
}

// Setters
void Vehicle::setCurrentLocation(int location)
{
    currentLocation = location;
}

void Vehicle::setDestination(int destination)
{
    this->destination = destination;
}

// Display
void Vehicle::display() const
{
    std::cout << "\n===== Vehicle =====\n";

    std::cout << "Vehicle ID : "
              << vehicleId << "\n";

    std::cout << "Type : "
              << type << "\n";

    std::cout << "Current Location : "
              << currentLocation << "\n";

    std::cout << "Destination : "
              << destination << "\n";

    std::cout << "Speed : "
              << speed
              << " km/h\n";

    std::cout << "Emergency : "
              << (emergency ? "YES" : "NO")
              << "\n";
}
