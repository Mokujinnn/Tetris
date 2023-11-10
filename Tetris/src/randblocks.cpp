#include "randblocks.hpp"

RandBlocks::RandBlocks(const sf::Vector2f &tileSize)
{
    this->blocks = new Block *[7];

    this->blocks[0] = new IBlock(tileSize);
    this->blocks[1] = new OBlock(tileSize);
    this->blocks[2] = new ZBlock(tileSize);
    this->blocks[3] = new rZBlock(tileSize);
    this->blocks[4] = new TBlock(tileSize);
    this->blocks[5] = new LBlock(tileSize);
    this->blocks[6] = new JBlock(tileSize);

    nextBlock = this->blocks[rand() % 7];
}

RandBlocks::~RandBlocks()
{
    for (int i = 0; i < 7; i++)
    {
        delete this->blocks[i];
    }
    delete[] this->blocks;
}

Block *RandBlocks::randomBlock()
{
    int i = rand() % 7;

    return this->blocks[i];
}

Block &RandBlocks::getAndUpdate()
{
    Block *block = nextBlock;

    nextBlock = randomBlock();

    while (block->getId() == nextBlock->getId())
    {
        nextBlock = randomBlock();
    }

    return *block;
}
