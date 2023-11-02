#include "JBlock.hpp"

JBlock::JBlock(const sf::Vector2f& tileSize) : Block(tileSize)
{
    sf::Vector2i tiles0[] = {sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2)};
    sf::Vector2i tiles1[] = {sf::Vector2i(0, 1), sf::Vector2i(0, 2), sf::Vector2i(1, 1), sf::Vector2i(2, 1)};
    sf::Vector2i tiles2[] = {sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(2, 2)};
    sf::Vector2i tiles3[] = {sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 0), sf::Vector2i(2, 1)};

    sf::Vector2i *tiles[] = {tiles0, tiles1, tiles2, tiles3};

    this->setTiles(tiles);

    this->setId(7);

    this->setStartOfset(0, 3);
    this->setOfset(0, 3);
}