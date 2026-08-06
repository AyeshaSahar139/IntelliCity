#include "MainWindow.h"
#include <iostream>
MainWindow::MainWindow(Graph* graph)

    : window(sf::VideoMode({1200,800}),
             "IntelliCity Smart Traffic Simulator"),
      graph(graph),
      cityMap(graph)
{

    
    window.setFramerateLimit(60);
    if (!font.openFromFile("assets/Arial.ttf"))
    {
        std::cout << "Font failed to load\n";
    }
    vehicle.setPosition(100,200);
}

void MainWindow::run()
{
    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color(30,30,30));

        cityMap.draw(window);
vehicle.draw(window);
        window.display();
    }
}