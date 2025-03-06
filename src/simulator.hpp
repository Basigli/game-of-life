#pragma once
#include "grid.hpp"

class Simulator
{
public:
    Simulator(int screenWidth, int screenHeight, int cellSize);
    void setCellAlive(int x, int y);
    void setCellDead(int x, int y);
    void draw();
    std::vector<int> getNeighbours(int x, int y);
    int countAliveNeighbours(int x, int y);

    
private:
    int screenWidth;
    int screenHeight;
    int cellSize;
    Grid grid;
};
