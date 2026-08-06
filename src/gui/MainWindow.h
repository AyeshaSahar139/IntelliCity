#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

class MainWindow
{
private:
    sf::RenderWindow window;

public:
    MainWindow();

    void run();
};

#endif