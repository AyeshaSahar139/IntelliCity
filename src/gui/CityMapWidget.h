#ifndef CITYMAPWIDGET_H
#define CITYMAPWIDGET_H

#include <SFML/Graphics.hpp>
#include "../graph/Graph.h"

class CityMapWidget
{
private:
    Graph* graph;
sf::Font font;
public:
    CityMapWidget(Graph* graph);

    void draw(sf::RenderWindow& window);
};

#endif