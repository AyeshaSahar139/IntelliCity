#include "VehicleRenderer.h"

VehicleRenderer::VehicleRenderer()
{
    car.setRadius(6);
    car.setFillColor(sf::Color::Blue);
    car.setOrigin({6,6});
}

void VehicleRenderer::setPosition(float x,float y)
{
    car.setPosition({x,y});
}

void VehicleRenderer::draw(sf::RenderWindow& window)
{
    window.draw(car);
}