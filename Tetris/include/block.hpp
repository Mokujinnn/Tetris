#pragma once
#include "SFML/Graphics.hpp"

#define NUM_OF_ROTATIN_STATE 4
#define TILES_IN_FIGURE 4

class Block
{
private:
    sf::Vector2i      **tiles;
    sf::Vector2i        startOfset;
    sf::Vector2i        ofset;
    sf::RectangleShape *rects;
    int                 rotationState;
    int                 id;

public:
    Block(){};

    Block(const sf::Vector2f &tileSize);

    Block(const Block &block);

    Block &operator=(const Block &block);

    virtual ~Block();

    void setOfset(int row, int col);

    void setId(int id);

    int getId();

    int getRotationState();

    void setRotationState(int rotationState);

    void setTiles(sf::Vector2i **tiles);

    sf::Vector2i **getTiles();

    sf::Vector2i *getTilesPositions();

    void rotateCW();

    void rotateCCW();

    void move(int rows, int cols);

    void setStartOfset(int row, int col);

    void reset();

    sf::Vector2i getStartOfset();

    void updateRects(const sf::Vector2f &tileSize, float tilePadding);

    void drawBlock(sf::RenderWindow &window);
};