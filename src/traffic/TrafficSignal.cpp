#include "TrafficSignal.h"

#include <iostream>

TrafficSignal::TrafficSignal()
{
    intersectionId = 0;
    currentState = "RED";
    timer = 30;
}

TrafficSignal::TrafficSignal(int id,
                             std::string state,
                             int timer)
{
    intersectionId = id;
    currentState = state;
    this->timer = timer;
}

int TrafficSignal::getIntersectionId() const
{
    return intersectionId;
}

std::string TrafficSignal::getState() const
{
    return currentState;
}

int TrafficSignal::getTimer() const
{
    return timer;
}

void TrafficSignal::setState(std::string state)
{
    currentState = state;
}

void TrafficSignal::setTimer(int timer)
{
    this->timer = timer;
}

void TrafficSignal::nextState()
{
    if (currentState == "GREEN")
    {
        currentState = "YELLOW";
    }
    else if (currentState == "YELLOW")
    {
        currentState = "RED";
    }
    else
    {
        currentState = "GREEN";
    }
}

void TrafficSignal::display() const
{
    std::cout << "\n===== Traffic Signal =====\n";

    std::cout << "Intersection : "
              << intersectionId
              << "\n";

    std::cout << "State : "
              << currentState
              << "\n";

    std::cout << "Timer : "
              << timer
              << " sec\n";
}