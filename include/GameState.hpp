#pragma once
#include "randblocks.hpp"
#include "grid.hpp"

class GameState
{
private:

    Block*     CurrentBlock;
    GameGrid   Grid;
    RandBlocks RandBlocks;
    bool       gameOver;

public:

    GameState(int rows, int cols, sf::Vector2i tileSize, int tilePadding);

};