#pragma once
#include "blocks.hpp"

class RandBlocks
{
private:

    Block  nextBlock;

    Block* randomBlock();

public:

    RandBlocks() {};

    ~RandBlocks() {};

    Block nextBlock();

    Block getNextBlock();
};