#include "IBlock.hpp"


IBlock::IBlock()
{
    sf::Vector2i tiles0[] = {sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3)};
    sf::Vector2i tiles1[] = {sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2)};
    sf::Vector2i tiles2[] = {sf::Vector2i(2, 0), sf::Vector2i(2, 1), sf::Vector2i(2, 2), sf::Vector2i(2, 3)};
    sf::Vector2i tiles3[] = {sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1)};

    sf::Vector2i *tiles[] = {tiles0, tiles1, tiles2, tiles3};

    this->setTiles(tiles);

    this->setId(1);

    this->setStartOfset(-1, 3);
    this->setOfset(-1, 3);
}
