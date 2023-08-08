#pragma once
#include "position.hpp"
#include "SFML/Graphics.hpp"

#define NUM_OF_ROTATIN_STATE 4
#define TILES_IN_FIGURE 4

class Block
{
private:

    Position **     tiles;
    sf::Vector2i    startOfset;
    sf::Vector2i    ofset;
    int             rotationState;
    int             id;

protected:

    Block();

    void setId(int id);

    void setTiles(Position ** tiles);

    Position ** getTiles();

    Position* getTilePositions(int rotationState);

    void rotateCW();

    void rotateCCW();

    void move(int rows, int cols);

};