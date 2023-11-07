#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "GameState.hpp"

int main()
{
    srand(time(NULL));

    int rows = 20, cols = 10;
    int tilePadding = 2;

    sf::Vector2f tile(35, 35);

    float tileWidth = tile.x, tileHeight = tile.y;

    int windowHeight = tilePadding + (tile.x + tilePadding) * rows; 
    int windowWidth  = tilePadding + (tile.y + tilePadding) * cols;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tetris");

    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width/2) - windowWidth/2, 
    (sf::VideoMode::getDesktopMode().height/2) - windowHeight/2)); // Расположение окна на экране

    GameState Game(rows, cols, tile, tilePadding);

    sf::Clock clock;
    float t = 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();

        t += time;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    Game.moveBlockLeft();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    Game.moveBlockRight();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    Game.moveBlockDown();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma))
                {
                    Game.rotateBlockCCW();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period))
                {
                    Game.rotateBlockCW();
                }
            }
        }

        if(t > 1)
        {
            t -= 1;
            Game.moveBlockDown();
        }

        window.clear();
        Game.draw(window);
        window.display();
    }

    return 0;
}