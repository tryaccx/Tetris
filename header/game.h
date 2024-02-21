#pragma once

#include <vector>
#include "blocks.cpp"
#include "grid.h"

using namespace std;

class Game
{
public:
    Game();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;

private:
    bool IsBlockOutside();
    void RotateBlock();
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};