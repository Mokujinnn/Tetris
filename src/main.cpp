#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>


int main()
{
    srand(time(NULL));

    

    int poleHeight = 20, poleWidth = 10;
    int tilePadding = 2;

    sf::Vector2f tile(30, 30);
    float tileWidth = tile.x, tileHeight = tile.y;

    int windowHeight = tilePadding + (tile.x + tilePadding) * poleHeight; 
    int windowWidth  =  tilePadding + (tile.y + tilePadding) * poleWidth;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tetris");
    window.setPosition(sf::Vector2i(300, 150));

    sf::RectangleShape pole[poleHeight][poleWidth];
    sf::Clock clock;
    for(int i = 0; i < poleHeight; i++)
    {
        for(int j = 0; j < poleWidth; j++)
        {
            pole[i][j].setPosition(sf::Vector2f(tilePadding + tileWidth*j + tilePadding*j, tilePadding + tileHeight*i + tilePadding*i)); // Расположение поля на экране
            pole[i][j].setSize(tile);
            pole[i][j].setOutlineThickness(0);
            pole[i][j].setOutlineColor(sf::Color::Cyan);
        }
    }

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

        for(int i = 0; i < poleHeight; i++)
            for(int j = 0; j < poleWidth; j++)
                window.draw(pole[i][j]);

        window.display();
    }

    return 0;
}