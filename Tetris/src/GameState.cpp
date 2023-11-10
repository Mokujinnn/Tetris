#include "GameState.hpp"

GameState::GameState(int rows, int cols, sf::Vector2f tileSize, float tilePadding) : Grid(new GameGrid(rows, cols, tileSize, tilePadding)),
                                                                                     RandBlock(new RandBlocks(tileSize)),
                                                                                     gameOver(false),
                                                                                     CurrentBlock(tileSize)
{
    this->CurrentBlock = RandBlock->getAndUpdate();
}

GameState::~GameState()
{
    delete Grid;
    delete RandBlock;
}

bool GameState::isLegalPosition()
{
    sf::Vector2i *t = CurrentBlock.getTilesPositions();

    sf::Vector2i tiles[TILES_IN_FIGURE] = {t[0], t[1], t[2], t[3]};
    delete[] t;

    for (int i = 0; i < TILES_IN_FIGURE; i++)
    {
        sf::Vector2i tile = tiles[i];

        if (!Grid->isEmpty(tile.x, tile.y))
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

    CurrentBlock.updateRects(this->Grid->getTileSize(), this->Grid->getTilePadding());
}

void GameState::rotateBlockCCW()
{
    CurrentBlock.rotateCCW();

    if (!isLegalPosition())
    {
        CurrentBlock.rotateCW();
    }

    CurrentBlock.updateRects(this->Grid->getTileSize(), this->Grid->getTilePadding());
}

void GameState::moveBlockLeft()
{
    CurrentBlock.move(0, -1);

    if (!isLegalPosition())
    {
        CurrentBlock.move(0, 1);
    }

    CurrentBlock.updateRects(this->Grid->getTileSize(), this->Grid->getTilePadding());
}

void GameState::moveBlockRight()
{
    CurrentBlock.move(0, 1);

    if (!isLegalPosition())
    {
        CurrentBlock.move(0, -1);
    }

    CurrentBlock.updateRects(this->Grid->getTileSize(), this->Grid->getTilePadding());
}

bool GameState::isGameOver()
{
    return (Grid->isRowEmpty(0) && Grid->isRowEmpty(1));
}

void GameState::placeBlock() // Размещение блока на сетку
{
    sf::Vector2i *t = CurrentBlock.getTilesPositions();

    sf::Vector2i tiles[TILES_IN_FIGURE] = {t[0], t[1], t[2], t[3]};
    delete[] t;

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
        CurrentBlock = RandBlock->getAndUpdate();
        CurrentBlock.reset();
    }
}

void GameState::moveBlockDown()
{
    CurrentBlock.move(1, 0);

    if (!isLegalPosition())
    {
        CurrentBlock.move(-1, 0);
        placeBlock();
    }

    CurrentBlock.updateRects(this->Grid->getTileSize(), this->Grid->getTilePadding());
}

void GameState::draw(sf::RenderWindow &window)
{
    Grid->drawGrid(window);
    CurrentBlock.drawBlock(window);
}