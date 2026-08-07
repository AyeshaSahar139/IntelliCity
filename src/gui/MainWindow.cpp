#include "MainWindow.h"
#include <iostream>
MainWindow::MainWindow(Graph* graph)

    : window(sf::VideoMode({1200,800}),
             "IntelliCity Smart Traffic Simulator"),
      graph(graph),
      cityMap(graph)
{

    
    window.setFramerateLimit(60);
   vehicleRenderer.setPath({
    {100.f,200.f},   // F-8
    {300.f,250.f},   // Blue Area
    {150.f,400.f},   // I-8
    {500.f,350.f},   // Sector H-8
    {650.f,450.f},   // NUST
    {750.f,250.f},   // FAST
    {850.f,500.f}    // COMSATS
});
    if (!font.openFromFile("assets/Arial.ttf"))
    {
        std::cout << "Font failed to load\n";
    }
    
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
        vehicleRenderer.update();

vehicleRenderer.draw(window);

        window.display();
    }
}