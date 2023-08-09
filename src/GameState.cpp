#include "GameState.hpp"

GameState::GameState(int rows, int cols, sf::Vector2i tileSize, int tilePadding)
{
    this->Grid = GameGrid(rows, cols, tileSize, tilePadding);
}