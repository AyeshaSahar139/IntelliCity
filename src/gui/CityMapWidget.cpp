#include "CityMapWidget.h"
#include <iostream>
#include <SFML/Graphics.hpp>

CityMapWidget::CityMapWidget(Graph* graph)
{
    this->graph = graph;
if(!font.openFromFile("assets/Arial.ttf"))
    
    {
        std::cout << "CityMap font failed to load\n";
    }
}

void CityMapWidget::draw(sf::RenderWindow& window)
{
    if(graph==nullptr)
        return;

    const auto& vertices = graph->getVertices();
    const auto& roads = graph->getAdjacencyList();

    // Draw Roads
    for(const auto& pair : roads)
    {
        int sourceID = pair.first;

        const Vertex& source = vertices.at(sourceID);

        for(const Edge& edge : pair.second)
        {
            const Vertex& destination =
                vertices.at(edge.getDestinationId());

            /***sf::Vertex line[] =
            {
                sf::Vertex(
                    sf::Vector2f(source.getX(),source.getY()),
                    edge.getStatus() ?
                    sf::Color::White :
                    sf::Color::Red),

                sf::Vertex(
                    sf::Vector2f(destination.getX(),destination.getY()),
                    edge.getStatus() ?
                    sf::Color::White :
                    sf::Color::Red)
            };

            window.draw(line,2,sf::PrimitiveType::Lines);
        }***/
       sf::Vertex line[2];

line[0].position = sf::Vector2f(source.getX(), source.getY());
line[1].position = sf::Vector2f(destination.getX(), destination.getY());

line[0].color = edge.getStatus() ? sf::Color::White : sf::Color::Red;
line[1].color = edge.getStatus() ? sf::Color::White : sf::Color::Red;

window.draw(line, 2, sf::PrimitiveType::Lines);
        }
    }

    // Draw Vertices
    for(const auto& pair : vertices)
    {
        const Vertex& v = pair.second;

        sf::CircleShape circle(8);

        circle.setFillColor(sf::Color::Cyan);

        circle.setOrigin({8,8});

        circle.setPosition(
            sf::Vector2f(v.getX(),v.getY()));

        window.draw(circle);
        sf::Text text(font);

text.setString(v.getName());

text.setCharacterSize(16);

text.setFillColor(sf::Color::White);

text.setPosition(
    sf::Vector2f(
        v.getX() + 12,
        v.getY() - 10));

window.draw(text);
    }
}