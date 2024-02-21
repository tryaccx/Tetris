#include "block.h"

using namespace std;

Block::Block() 
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    row_offset = 0;
    column_offset = 0;
}

void Block::Draw()
{
    vector<Position> tiles = GetCellPositions();
    for (Position item: tiles)
    {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
   row_offset += rows;
   column_offset += columns; 
} 

vector<Position> Block::GetCellPositions()
{
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;

    for (Position item: tiles)
    {
        Position newPos = Position(item.row + row_offset, item.column + column_offset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if(rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
