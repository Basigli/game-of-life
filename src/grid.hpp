#pragma once
#include <vector>

class Grid 
{
public:
    Grid(int width, int height, int cellSize);
    void draw();
    void setCell(int x, int y, int value);
    int getCellValue(int x, int y);

private:
    int width;
    int height;
    int cellSize;
    std::vector<std::vector<int>> cells;

};

