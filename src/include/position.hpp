#pragma once

class Position
{
private:
    int row;
    int col;

public:

    Position(int row = 0, int col = 0);

    int getRow();

    void setRow(int row);

    int getCol();

    void setCol(int col);

};