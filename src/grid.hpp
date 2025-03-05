#pragma once
#include <vector>

class Grid 
{
public:
    Grid(int width, int height, int cellSize);
    void draw();

private:
    int width;
    int height;
    int cellSize;
    std::vector<std::vector<int>> cells;

};

