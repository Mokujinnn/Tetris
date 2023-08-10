#include "block.hpp"
#include <iostream>

Block::Block()
{
    tiles = new sf::Vector2i * [NUM_OF_ROTATIN_STATE];
    tiles[0] = new sf::Vector2i [NUM_OF_ROTATIN_STATE * TILES_IN_FIGURE];

    for (int i = 1; i < NUM_OF_ROTATIN_STATE; i++)
    {
        tiles[i] = tiles[i - 1] + TILES_IN_FIGURE;
    }

    this->rotationState = 0;
}

Block::~Block()
{
    delete [] this->tiles[0];
    delete [] this->tiles;
}

void Block::setOfset(int row, int col)
{
    this->ofset = sf::Vector2i(row, col);
}

void Block::setId(int id)
{
    this->id = id;
}

int Block::getId()
{
    return this->id;
}

int Block::getRotationState()
{
    return this->rotationState;
}

void Block::setRotationState(int rotationState)
{
    this->rotationState = rotationState;
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
    for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    {
        for (int j = 0; j < TILES_IN_FIGURE; j++)
        {
            std::cout << this->tiles[i][j].x << ' ' << tiles[i][j].y << '\t';
        }
        std::cout << '\n';
    }
}

sf::Vector2i ** Block::getTiles()
{
    return this->tiles;
}

sf::Vector2i* Block::getTilePositions()
{
    return tiles[this->rotationState];
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

void Block::setStartOfset(int row, int col)
{
    this->startOfset = sf::Vector2i(row, col);
}

sf::Vector2i Block::getStartOfset()
{
    return this->startOfset;
}
