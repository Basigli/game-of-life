#include "simulator.hpp"

Simulator::Simulator(int screenWidth, int screenHeight, int cellSize): screenWidth(screenWidth), screenHeight(screenHeight), cellSize(cellSize), grid(screenWidth, screenHeight, cellSize)
{
}

void Simulator::setCellAlive(int x, int y)
{
    grid.setCell(x, y, 1);
}

void Simulator::setCellDead(int x, int y)
{
    grid.setCell(x, y, 0);
}
