#include "randblocks.hpp"

RandBlocks::RandBlocks()
{
    nextBlock = randomBlock();
}

RandBlocks::~RandBlocks()
{

}

Block RandBlocks::randomBlock()
{
    int i = rand() % 7;

    IBlock a;
    OBlock b;
    ZBlock c;
    rZBlock d;
    TBlock e;
    LBlock f;
    JBlock g;

    Block blocks[] = {a, b, c, d, e, f, g};

    return blocks[i];    
}

Block RandBlocks::getAndUpdate()
{
    Block block = nextBlock;

    nextBlock = randomBlock();

    while (block.getId() == nextBlock.getId())
    {
        nextBlock = randomBlock();
    }

    return block;
}

