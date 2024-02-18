#pragma once
#include <vector>
#include "raylib.h"

using namespace std;

class Grid
{
public:
    Grid();
    void Initialize();
    void Print();
    int grid[20][10];
private:
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;
};

