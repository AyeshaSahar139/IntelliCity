#include "CityMapWidget.h"

#include <SFML/Graphics.hpp>
#include <iostream>

CityMapWidget::CityMapWidget(Graph* graph)
{
    this->graph = graph;
}

void CityMapWidget::draw(sf::RenderWindow& window)
{
    if (graph == nullptr)
        return;

    // Drawing implementation will be added in the next step.
}