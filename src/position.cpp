#include "position.hpp"

    Position::Position(int row, int col) : row(row), col(col) {}

    int Position::getRow()
    {
        return this->row;
    }

    void Position::setRow(int row)
    {
        this->row = row;
    }

    int Position::getCol()
    {
        return this->col;
    }

    void Position::setCol(int col)
    {
        this->col = col;
    }