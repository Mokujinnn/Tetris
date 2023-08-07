#pragma once
#include "SFML/Graphics.hpp"

class GameGrid
{
private:

int                   cols;
int                   rows;
int                   tilePadding;
sf::Vector2f          tileSize;

int **                grid;
sf::RectangleShape ** tiles;

public:

    GameGrid(int rows, int cols, sf::Vector2f tile, int tilePadding);

    ~GameGrid();

    bool isInside(int rows, int cols);

    bool isEmpty(int rows, int cols);

    bool isRowFull(int row);

    bool isRowEmpty(int row);

    void drawGrid(sf::RenderWindow &window);
};