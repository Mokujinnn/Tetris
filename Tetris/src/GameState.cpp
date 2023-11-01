#include "GameState.hpp"

GameState::GameState(int rows, int cols, sf::Vector2f tileSize, int tilePadding)
{
    this->Grid = new GameGrid(rows, cols, tileSize, tilePadding);
    this->RandBlock = RandBlocks();
    this->CurrentBlock = RandBlock.getAndUpdate();
}

GameState::~GameState()
{
    delete Grid;
}

bool GameState::isLegalPosition()
{
    sf::Vector2i* t = CurrentBlock.getTilesPositions();

    sf::Vector2i tiles[TILES_IN_FIGURE] = {t[0], t[1], t[2], t[3]};
    delete [] t;

    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        sf::Vector2i tile = tiles[i];

        if(!Grid->isEmpty(tile.x, tile.y))
            return false;
    }

    return true;
}

void GameState::rotateBlockCW()
{
    CurrentBlock.rotateCW();

    if (!isLegalPosition())
    {
        CurrentBlock.rotateCCW();
    }
}

void GameState::rotateBlockCCW()
{
    CurrentBlock.rotateCCW();

    if (!isLegalPosition())
    {
        CurrentBlock.rotateCW();
    }
}

void GameState::moveBlockLeft()
{
    CurrentBlock.move(0, -1);

    if (!isLegalPosition())
    {
        CurrentBlock.move(0, 1);
    }
}

void GameState::moveBlockRight()
{
    CurrentBlock.move(0, 1);

    if (!isLegalPosition())
    {
        CurrentBlock.move(0, -1);
    }
}

bool GameState::isGameOver()
{
    return (Grid->isRowEmpty(0) && Grid->isRowEmpty(1));
}

void GameState::placeBlock() //Размещение блока на сетку
{
    sf::Vector2i* t = CurrentBlock.getTilesPositions();

    sf::Vector2i tiles[TILES_IN_FIGURE] = {t[0], t[1], t[2], t[3]};
    delete [] t;

    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        Grid->setTileId(tiles[i].x, tiles[i].y, CurrentBlock.getId());
    }

    Grid->clearFullRows();

    if (!isGameOver())
    {
        this->gameOver = true;
    }
    else
    {
        CurrentBlock = RandBlock.getAndUpdate();
    }
}

void GameState::moveBlockDown()
{
    CurrentBlock.move(1, 0);

    if (!isLegalPosition())
    {
        CurrentBlock.move(-1, 0); // CurrentBlock.move(0, -1);
        placeBlock();
    }
}

void GameState::draw(sf::RenderWindow *window)
{
    this->Grid->drawGrid(window);
}