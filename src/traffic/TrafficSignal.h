#ifndef TRAFFICSIGNAL_H
#define TRAFFICSIGNAL_H

#include <string>

class TrafficSignal
{
private:
    int intersectionId;
    std::string currentState;
    int timer;

public:
    TrafficSignal();

    TrafficSignal(int id,
                  std::string state,
                  int timer);

    int getIntersectionId() const;
    std::string getState() const;
    int getTimer() const;

    void setState(std::string state);
    void setTimer(int timer);

    void nextState();

    void display() const;
};

#endif