#include "include/block.hpp"
#include "SFML/Graphics.hpp"

Block::Block()
{
    startOfset = sf::Vector2i(3, 0);
}

sf::Vector2i* Block::getTilePositions(int rotationState)
{
    return tiles[rotationState];
}