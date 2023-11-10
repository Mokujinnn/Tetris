#pragma once
#include <vector>

#include "blocks.hpp"

class RandBlocks
{
private:
    Block  *nextBlock;
    Block **blocks;

    Block *randomBlock();

public:
    // RandBlocks() {};

    RandBlocks(const sf::Vector2f &tileSize);

    ~RandBlocks();

    Block &getAndUpdate();
};