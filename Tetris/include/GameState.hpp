#pragma once
#include "randblocks.hpp"
#include "grid.hpp"

class GameState
{
private:
    Block       CurrentBlock;
    GameGrid   *Grid;
    RandBlocks *RandBlock;
    bool        gameOver;

public:
    GameState(int rows, int cols, sf::Vector2f tileSize, float tilePadding);

    ~GameState();

    bool isLegalPosition();

    void rotateBlockCW();

    void rotateBlockCCW();

    void moveBlockLeft();

    void moveBlockRight();

    void moveBlockDown();

    bool isGameOver();

    void placeBlock();

    void draw(sf::RenderWindow &window);
};