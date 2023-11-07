#include "block.hpp"
#include <iostream>

Block::Block(const sf::Vector2f& tileSize)
{
    tiles = new sf::Vector2i * [NUM_OF_ROTATIN_STATE];
    tiles[0] = new sf::Vector2i [NUM_OF_ROTATIN_STATE * TILES_IN_FIGURE];

    for (int i = 1; i < NUM_OF_ROTATIN_STATE; i++)
    {
        tiles[i] = tiles[i - 1] + TILES_IN_FIGURE;
    }

    this->rotationState = 0;

    this->rects = new sf::RectangleShape[TILES_IN_FIGURE];

    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        this->rects[i].setSize(tileSize);
        this->rects[i].setFillColor(sf::Color::Red);
        this->rects[i].setPosition(-100, -100);
    }
}

Block::Block(Block const & block) : startOfset(block.startOfset), ofset(block.ofset), rotationState(block.rotationState), id(block.id)
{
    this->tiles = new sf::Vector2i * [NUM_OF_ROTATIN_STATE];
    this->tiles[0] = new sf::Vector2i [NUM_OF_ROTATIN_STATE * TILES_IN_FIGURE];

    for (int i = 1; i < NUM_OF_ROTATIN_STATE; i++)
    {
        tiles[i] = tiles[i - 1] + TILES_IN_FIGURE;
    }

    for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    {
        for (int j = 0; j < TILES_IN_FIGURE; j++)
        {
            this->tiles[i][j] = block.tiles[i][j];
        }
    }

    this->rects = new sf::RectangleShape[TILES_IN_FIGURE];

    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        this->rects[i] = block.rects[i];
    }
}

//Block Block::operator=(const Block& block)
//{
//    if (this != &block)
//    {
//        delete [] this->tiles[0];
//        delete [] this->tiles;
//
//        this->startOfset    = block.startOfset;
//        this->ofset         = block.ofset;
//        this->rotationState = block.rotationState;
//        this->id            = block.id; 
//
//        this->tiles = new sf::Vector2i * [NUM_OF_ROTATIN_STATE];
//        this->tiles[0] = new sf::Vector2i [NUM_OF_ROTATIN_STATE * TILES_IN_FIGURE];
//
//        for (int i = 1; i < NUM_OF_ROTATIN_STATE; i++)
//        {
//            tiles[i] = tiles[i - 1] + TILES_IN_FIGURE;
//        }
//        for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
//        {
//            for (int j = 0; j < TILES_IN_FIGURE; j++)
//            {
//                this->tiles[i][j] = block.tiles[i][j];
//            }
//        }
//    }
//
//    return *this;
//}

Block::~Block()
{
    delete[] this->tiles[0];
    delete[] this->tiles;

    delete[] this->rects;
}

void Block::setOfset(int row, int col)
{
    this->ofset = sf::Vector2i(row, col);
}

void Block::setId(int id)
{
    this->id = id;
}

int Block::getId()
{
    return this->id;
}

int Block::getRotationState()
{
    return this->rotationState;
}

void Block::setRotationState(int rotationState)
{
    this->rotationState = rotationState;
}

void Block::reset()
{
    this->ofset = this->startOfset;
}

void Block::setTiles(sf::Vector2i ** tiles)
{
    for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    {
        for (int j = 0; j < TILES_IN_FIGURE; j++)
        {
            this->tiles[i][j] = tiles[i][j];
        }
    }
    // for (int i = 0; i < NUM_OF_ROTATIN_STATE; i++)
    // {
    //     for (int j = 0; j < TILES_IN_FIGURE; j++)
    //     {
    //         std::cout << this->tiles[i][j].x << ' ' << tiles[i][j].y << '\t';
    //     }
    //     std::cout << '\n';
    // }
}

sf::Vector2i ** Block::getTiles()
{
    return this->tiles;
}

sf::Vector2i* Block::getTilesPositions()
{
    sf::Vector2i* t = tiles[this->rotationState];

    sf::Vector2i* block = new sf::Vector2i[TILES_IN_FIGURE];
    
    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        block[i] = t[i];
        block[i] += ofset;
    }

   /* for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        std::cout << block[i].x << ' ' << block[i].y << '\n';
    }
    std::cout << "----------------------\n";*/

    return block;
}

void Block::rotateCW()
{
    rotationState = (rotationState + 1) % NUM_OF_ROTATIN_STATE;
}

void Block::rotateCCW()
{
    if (rotationState == 0)
    {
        rotationState = NUM_OF_ROTATIN_STATE - 1;
    }
    else
    {
        rotationState--;
    }
}

void Block::move(int rows, int cols)
{
    ofset.x += rows;
    ofset.y += cols;
}

void Block::setStartOfset(int row, int col)
{
    this->startOfset = sf::Vector2i(row, col);
}

sf::Vector2i Block::getStartOfset()
{
    return this->startOfset;
}

void Block::updateRects(const sf::Vector2f& tileSize, int tilePadding)
{
    sf::Vector2i* pos = getTilesPositions();
    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        this->rects[i].setPosition(tilePadding + tileSize.y * pos[i].y + tilePadding * pos[i].y,
                                   tilePadding + tileSize.x * pos[i].x + tilePadding * pos[i].x);
    }

    delete[] pos;
}

void Block::drawBlock(sf::RenderWindow& window)
{
    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        window.draw(this->rects[i]);
    }
}