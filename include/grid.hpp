#pragma once
#include "SFML/Graphics.hpp"

class GameGrid
{
private:

    int                   cols;
    int                   rows;
    float                 tilePadding;
    sf::Vector2f          tileSize;

    int **                grid;
    sf::RectangleShape ** tiles;

public:

    GameGrid(int rows, int cols, sf::Vector2f tile, float tilePadding);

    ~GameGrid();

    bool isInside(int rows, int cols);

    bool isEmpty(int rows, int cols);

    bool isRowFull(int row);

    bool isRowEmpty(int row);

    void drawGrid(sf::RenderWindow &window);

    int getTileId(int row, int col);

    void setTileId(int row, int col, int id);
};