#include "include/block.hpp"
#include "SFML/Graphics.hpp"



Block::Block()
{
    tiles = new sf::Vector2i * [NUM_OF_ROTATIN_STATE];
    tiles[0] = new sf::Vector2i [NUM_OF_ROTATIN_STATE * TILES_IN_FIGURE];
    for (int i = 1; i < NUM_OF_ROTATIN_STATE; i++)
    {
        tiles[i] = tiles[i - 1] + TILES_IN_FIGURE;
    }
}

Block::~Block()
{
    delete [] tiles[0];
    delete [] tiles;
}

void Block::setId(int id)
{
    this->id = id;
}

void Block::setTiles(sf::Vector2i ** tiles)
{
    for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    {
        for (int j = 0; j < TILES_IN_FIGURE; j++)
        {
            this->tiles[i][j] = tiles[i][j];
        }
    }
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