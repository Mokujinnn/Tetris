#include "include/IBlock.hpp"
#include <iostream>

IBlock::IBlock()
{
    sf::Vector2i tiles0[] = {sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3)};
    sf::Vector2i tiles1[] = {sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2)};
    sf::Vector2i tiles2[] = {sf::Vector2i(2, 0), sf::Vector2i(2, 1), sf::Vector2i(2, 2), sf::Vector2i(2, 3)};
    sf::Vector2i tiles3[] = {sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1)};

    sf::Vector2i *tiles[] = {tiles0, tiles1, tiles2, tiles3};

    this->setTiles(tiles);

    for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    {
        for (int j = 0; j < TILES_IN_FIGURE; j++)
        {
            std::cout << tiles[i][j].x << ' ' << tiles[i][j].x << '\n';
        }
        std::cout << '\n';
    }

    

    this->setId(1);
}
