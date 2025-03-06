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

void Simulator::draw()
{
    grid.draw();
}

std::vector<int> Simulator::getNeighbours(int x, int y)
{
    std::vector<int> neighbours;
    std::vector<std::vector<int>> directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    int rows = grid.getRows();
    int cols = grid.getCols();

    for (auto direction : directions)
    {
        int neighbourX = (x + direction[0]) % cols;
        int neighbourY = (y + direction[1]) % rows;
        if (neighbourX >= 0 && neighbourX < cols && neighbourY >= 0 && neighbourY < rows)
        {
            neighbours.push_back(grid.getCellValue(neighbourX, neighbourY));
        }
    }
    return neighbours;
}

int Simulator::countAliveNeighbours(int x, int y)
{
    int aliveNeighbours = 0;
    std::vector<int> neighbours = getNeighbours(x, y);
    for (int neighbour : neighbours)
    {
        aliveNeighbours += neighbour;
    }
    return aliveNeighbours;
}
