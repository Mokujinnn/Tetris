#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "grid.hpp"
#include "IBlock.hpp"
#include "OBlock.hpp"

int main()
{
    srand(time(NULL));

    int rows = 20, cols = 10;
    int tilePadding = 2;

    sf::Vector2f tile(35, 35);
    float tileWidth = tile.x, tileHeight = tile.y;

    int windowHeight = tilePadding + (tile.x + tilePadding) * rows; 
    int windowWidth  =  tilePadding + (tile.y + tilePadding) * cols;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tetris");

    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2) - windowWidth/2, 
    (sf::VideoMode::getDesktopMode().height/2) - windowHeight/2)); // Расположение окна на экране

    GameGrid Grid(rows, cols, tile, tilePadding);
    sf::Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Grid.drawGrid(window);

        window.display();
    }

    OBlock i;

    return 0;
}