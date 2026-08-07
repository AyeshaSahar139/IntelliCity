#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

#include "../graph/Graph.h"
#include "CityMapWidget.h"
#include "VehicleRenderer.h"
class MainWindow
{
private:
VehicleRenderer vehicleRenderer;;
    sf::RenderWindow window;
sf::Font font;
    Graph* graph;

    CityMapWidget cityMap;

public:

    MainWindow(Graph* graph);

    void run();
};

#endif