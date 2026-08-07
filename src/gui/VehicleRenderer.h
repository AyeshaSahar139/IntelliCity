#ifndef VEHICLERENDERER_H
#define VEHICLERENDERER_H
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class VehicleRenderer
{
private:
    sf::Texture texture;
    std::unique_ptr<sf::Sprite> sprite;
std::vector<sf::Vector2f> path;

int currentTarget = 0;

float speed = 2.0f;
public:
    VehicleRenderer();

    void update();

    void draw(sf::RenderWindow& window);
    void setPath(const std::vector<sf::Vector2f>& newPath);
};

#endif