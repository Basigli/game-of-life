#include "simulator.hpp"

Simulator::Simulator(int screenWidth, int screenHeight, int cellSize): grid(screenWidth, screenHeight, cellSize)
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

void Simulator::updateStatus()
{
    std::vector<std::vector<int>> cellsToUpdate;
    for (int x = 0; x <= grid.getCols(); x++)
    {
        for (int y = 0; y <= grid.getRows(); y++)
        {
            if (needsUpdate(x, y)) 
                cellsToUpdate.push_back({x, y});
            
        }
    }
    for (auto cell : cellsToUpdate)
        grid.setCell(cell[0], cell[1], !grid.getCellValue(cell[0], cell[1]));
    
    
}

bool Simulator::needsUpdate(int x, int y)
{
    int aliveNeighbours = countAliveNeighbours(x, y);
    int cellValue = grid.getCellValue(x, y);
    if (cellValue == 1)
    {
        if (aliveNeighbours < 2 || aliveNeighbours > 3)            
            return true;
    } else 
    {
        if (aliveNeighbours == 3)
            return true;
    }
    return false;
}
