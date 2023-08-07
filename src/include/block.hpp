#pragma once
#include "SFML/Graphics.hpp"

class Block
{
private:

    sf::Vector2i ** tiles;
    sf::Vector2i    startOfset;
    int             rotationState;


public:

    Block();

    ~Block() {};

    sf::Vector2i* getTilePositions(int rotationState);

    void rotateCW();

    void rotateCCW();

    void move(int rows, int cols);
};