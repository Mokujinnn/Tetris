#include "include/block.hpp"
#include "SFML/Graphics.hpp"

#define NUM_OF_ROTATIN_STATE 4

Block::Block()
{
    startOfset = sf::Vector2i(3, 0);
    ofset = startOfset;
}

sf::Vector2i* Block::getTilePositions(int rotationState)
{
    return tiles[rotationState];
}

void Block::rotateCW()
{
    rotationState = (rotationState + 1) % NUM_OF_ROTATIN_STATE;
}

void Block::rotateCCW()
{
    if (rotationState == 0)
    {
        rotationState = NUM_OF_ROTATIN_STATE - 1;
    }
    else
    {
        rotationState--;
    }
}

void Block::move(int rows, int cols)
{
    ofset.x += rows;
    ofset.y += cols;
}