#include "Edge.h"

// Default Constructor
Edge::Edge()
{
    sourceId = 0;
    destinationId = 0;
    distance = 0.0;
    trafficFactor = 1.0;
    isOpen = true;
}

// Parameterized Constructor
Edge::Edge(int sourceId, int destinationId, double distance, double trafficFactor)
{
    this->sourceId = sourceId;
    this->destinationId = destinationId;
    this->distance = distance;
    this->trafficFactor = trafficFactor;
    this->isOpen = true;
}

// Getters
int Edge::getSourceId() const
{
    return sourceId;
}

int Edge::getDestinationId() const
{
    return destinationId;
}

double Edge::getDistance() const
{
    return distance;
}

double Edge::getTrafficFactor() const
{
    return trafficFactor;
}

bool Edge::getStatus() const
{
    return isOpen;
}

// Setters
void Edge::setSourceId(int sourceId)
{
    this->sourceId = sourceId;
}

void Edge::setDestinationId(int destinationId)
{
    this->destinationId = destinationId;
}

void Edge::setDistance(double distance)
{
    this->distance = distance;
}

void Edge::setTrafficFactor(double trafficFactor)
{
    this->trafficFactor = trafficFactor;
}

void Edge::setStatus(bool status)
{
    isOpen = status;
}