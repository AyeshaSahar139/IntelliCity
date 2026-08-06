#ifndef VEHICLERENDERER_H
#define VEHICLERENDERER_H

#include <SFML/Graphics.hpp>

class VehicleRenderer
{
private:
    sf::CircleShape car;

public:
    VehicleRenderer();

    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);
};

#endif