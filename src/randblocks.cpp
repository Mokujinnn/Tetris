#include "randblocks.hpp"

Block* RandBlocks::randomBlock()
{
    int block = rand() % 7;
    switch (block)
    {
    case 0:
        return new IBlock;
    case 1:
        return new OBlock;
    case 2:
        return new ZBlock;
    case 3:
        return new rZBlock;
    case 4:
        return new TBlock;
    case 5:
        return new LBlock;
    case 6:
        return new JBlock;
    default:
        break;
    }
}

