#include <iostream>

#include "city/CityManager.h"
#include "gui/MainWindow.h"
int main()
{
    CityManager city;

    if (!city.loadCityMap())
    {
        std::cout << "Failed to load city map.\n";
        return 1;
    }

    city.displayCity();

    std::cout << "\nIntelliCity initialized successfully.\n";
    std::cout << "Launching GUI...\n";
    MainWindow app;
app.run();
std::cout << "GUI Closed.\n";
    return 0;
}