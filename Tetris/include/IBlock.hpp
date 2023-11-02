#pragma once
#include "SFML/Graphics.hpp"
#include "block.hpp"

class IBlock : public Block
{
public:

    IBlock(const sf::Vector2f& tileSize);

    ~IBlock() {};

};