#include "VehicleRenderer.h"
#include <cmath>
#include <iostream>
#include <memory>

VehicleRenderer::VehicleRenderer()
{
    if (!texture.loadFromFile("assets/Car.png"))
    {
        std::cout << "Car image failed to load\n";
        return;
    }

    sprite = std::make_unique<sf::Sprite>(texture);

    sprite->setScale({0.08f,0.08f});

    sprite->setOrigin({
        texture.getSize().x/2.f,
        texture.getSize().y/2.f
    });

    sprite->setPosition({100.f,200.f});
}

void VehicleRenderer::update()
{
    if (!sprite || path.empty())
        return;

    if (currentTarget >= path.size())
        return;

    sf::Vector2f currentPosition = sprite->getPosition();

    sf::Vector2f target = path[currentTarget];

    sf::Vector2f direction = target - currentPosition;

    float length =
        std::sqrt(direction.x * direction.x +
                  direction.y * direction.y);

    if (length < speed)
    {
        sprite->setPosition(target);

        currentTarget++;

        return;
    }

    direction /= length;

    sprite->move(direction * speed);
}

void VehicleRenderer::draw(sf::RenderWindow& window)
{
    if(sprite)
        window.draw(*sprite);
}
void VehicleRenderer::setPath(const std::vector<sf::Vector2f>& newPath)
{
    path = newPath;

    currentTarget = 0;

    if (!path.empty() && sprite)
    {
        sprite->setPosition(path[0]);
    }
}