#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>



int main()
{
    srand(time(NULL));

    sf::Clock clock;

    int windowHeight = 720, windowWidth = 1280;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Test");
    window.setPosition(sf::Vector2i(300, 150));
    window.setVerticalSyncEnabled(true);

    int poleHeight = 15, poleWidth = 10;
    int poleBlocksPadding = 2;

    float blockWidth = 40, blockHeight = 40;
    sf::Vector2f sizeBlocks(blockWidth, blockHeight);

    sf::RectangleShape pole[poleHeight][poleWidth];

    for(int i = 0; i < poleHeight; i++)
    {
        for(int j = 0; j < poleWidth; j++)
        {
            pole[i][j].setPosition(sf::Vector2f(blockWidth*j - blockWidth/2 + poleBlocksPadding*j + windowWidth/2 - poleWidth * blockWidth / 2, blockHeight*i - blockHeight/2 + poleBlocksPadding*i + windowHeight/2 - poleHeight * blockHeight / 2)); // Расположение поля на экране
            pole[i][j].setSize(sizeBlocks);
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