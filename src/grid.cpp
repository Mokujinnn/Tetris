#include "SFML/Graphics.hpp"
#include "grid.hpp"

GameGrid::GameGrid(int rows, int cols,  sf::Vector2f tileSize, float tilePadding)
{
    this->cols        = cols;
    this->rows        = rows;
    this->tileSize    = tileSize;
    this->tilePadding = tilePadding;

    grid = new int * [rows];
    grid[0] = new int[cols * rows];
    for (int i = 1; i < rows; i++)
    {
        grid[i] = grid[i - 1] + cols;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = 0;
        }
    }


    tiles = new sf::RectangleShape * [rows];
    tiles[0] = new sf::RectangleShape[cols * rows];
    for (int i = 1; i < rows; i++)
    {
        tiles[i] = tiles[i - 1] + cols;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tiles[i][j].setSize(tileSize);
            tiles[i][j].setPosition(sf::Vector2f(tilePadding + tileSize.x*j + tilePadding*j, tilePadding + tileSize.y*i + tilePadding*i));
            tiles[i][j].setOutlineThickness(tilePadding);
            tiles[i][j].setOutlineColor(sf::Color(210, 210, 210));
        }
    }
}

GameGrid::~GameGrid()
{
    delete [] grid[0];
    delete [] grid;

    delete [] tiles[0];
    delete [] tiles;
}

bool GameGrid::isInside(int rows, int cols)
{
    return cols >= 0 && cols < this->cols && rows >= 0 && rows <= this->rows;
}

bool GameGrid::isEmpty(int rows, int cols)
{
    return isInside(rows, cols) && grid[rows][cols] == 0;
}

bool GameGrid::isRowFull(int row)
{
    for (int i = 0; i < cols; i ++)
    {
        if (grid[rows][i] == 0)
            return false;
    }
    return true;
}

bool GameGrid::isRowEmpty(int row)
{
    for (int i = 0; i < cols; i ++)
    {
        if (grid[rows][i] != 0)
            return false;
    }
    return true;
}

void GameGrid::drawGrid(sf::RenderWindow &window)
{

    window.clear();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            window.draw(tiles[i][j]);
        }
    }       
}

int GameGrid::getTileId(int row, int col)
{
    return grid[row][col];
}

void GameGrid::setTileId(int row, int col, int id)
{
    grid[row][col] = id;
}