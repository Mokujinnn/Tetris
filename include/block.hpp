#pragma once
#include "SFML/Graphics.hpp"

#define NUM_OF_ROTATIN_STATE 4
#define TILES_IN_FIGURE 4

class Block
{
private:

    sf::Vector2i ** tiles;
    sf::Vector2i    startOfset;
    sf::Vector2i    ofset;
    int             rotationState;
    int             id;

public:

    Block();

    virtual ~Block();

    void setId(int id);

    int getId();

    void setTiles(sf::Vector2i ** tiles);

    sf::Vector2i ** getTiles();

    sf::Vector2i* getTilePositions(int rotationState);

    void rotateCW();

    void rotateCCW();

    void move(int rows, int cols);

    void setStartOfset(int row, int col);

    sf::Vector2i getStartOfset();

};