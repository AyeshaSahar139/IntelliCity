#include <iostream>

#include "graph/Graph.h"
#include "graph/Vertex.h"
#include "graph/Edge.h"
#include "traffic/TrafficSignal.h"
#include "incident/Incident.h"
#include "vehicle/Vehicle.h"


int main()
{
    Graph city;

    Vertex v1(1, "F-8", 100, 200);
    Vertex v2(2, "Blue Area", 300, 250);
    Vertex v3(3, "I-8", 150, 400);

    city.addVertex(v1);
    city.addVertex(v2);
    city.addVertex(v3);

    Edge e1(1, 2, 5.0, 1.2);
Edge e2(2, 3, 4.5, 1.1);
Edge e3(1, 3, 7.2, 1.5);

city.addEdge(e1);
city.addEdge(e2);
city.addEdge(e3);





city.displayGraph();

std::cout << "\nTravel Cost Example\n";

Edge sampleRoad(1, 2, 5.0, 1.2);

std::cout
    << "Cost : "
    << city.calculateTravelCost(sampleRoad)
    << " km\n";

std::cout
    << "Estimated Time : "
    << city.estimateTravelTime(sampleRoad)
    << " hours\n";
    std::cout << "\n===== Neighbors of F-8 =====\n";
std::vector<Edge> neighbors = city.getNeighbors(1);

for (const Edge& edge : neighbors)
{
    Vertex destination = city.getVertex(edge.getDestinationId());

    std::cout
        << destination.getName()
        << " | Distance: "
        << edge.getDistance()
        << " km"
        << " | Traffic: "
        << edge.getTrafficFactor()
        << "\n";
}
std::cout << "\nRunning BFS from F-8\n";

city.bfs(1);
std::cout << "\nRunning DFS from F-8\n";

city.dfs(1);

std::cout << "\nRunning Dijkstra from F-8\n";
std::cout << "\nClosing Road F-8 -> I-8\n";

city.closeRoad(1, 3);
city.dijkstra(1);
std::cout << "\nRunning Dijkstra after road closure\n";

city.dijkstra(1);
std::cout << "\nRunning Shortest Path from F-8 to I-8\n";
std::cout << "\nRunning Shortest Path\n";

city.shortestPath(1,3);
std::cout << "\nOpening Road F-8 -> I-8\n";
city.openRoad(1, 3);
std::cout << "\nUpdating Traffic F-8 -> I-8\n";
city.updateTraffic(1, 3, 2.8);
city.displayGraph();
std::cout << "\nRunning Dijkstra after reopening road\n";
city.dijkstra(1);

std::cout << "\nRunning Shortest Path Again\n";
city.shortestPath(1, 3);
std::cout << "\nRunning Emergency Route\n";
city.emergencyRoute(1, 3);
std::cout << "\nRunning Route Recommendation\n";
city.recommendRoute(1,3);

std::cout << "\nTraffic Signal Demo\n";

TrafficSignal trafficSignal(1, "GREEN", 30);

trafficSignal.display();

trafficSignal.nextState();
trafficSignal.display();

trafficSignal.nextState();
trafficSignal.display();

trafficSignal.nextState();
trafficSignal.display();
std::cout << "\nIncident Demo\n";

Incident incident1(
    101,
    1,
    3,
    "Accident",
    "High"
);

incident1.display();

std::cout << "\nResolving Incident...\n";

incident1.resolve();

incident1.display();
std::cout << "\nVehicle Demo\n";

Vehicle vehicle1(
    1,
    "Car",
    1,
    3,
    60,
    false
);

vehicle1.display();
    return 0;
}
