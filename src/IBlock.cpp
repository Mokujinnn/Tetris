#include "include/IBlock.hpp"


IBlock::IBlock()
{
    Position tiles0[] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    Position tiles1[] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    Position tiles2[] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    Position tiles3[] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};

    Position *tiles[] = {tiles0, tiles1, tiles2, tiles3};

    this->setTiles(tiles);

    this->setId(1);

    
}

IBlock::~IBlock() 
{
    Position ** t = this->getTiles();
    delete [] t[0];
    delete [] t;
}
