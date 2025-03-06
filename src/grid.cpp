#include "grid.hpp"
#include <raylib.h>

Grid::Grid(int width, int height, int cellSize) : width(width), height(height), cellSize(cellSize), cells(width/cellSize, std::vector<int>(height/cellSize, 0))
{
}

void Grid::draw()
{
    for (int x = 0; x < width/cellSize; x++)
    {
        for (int y = 0; y < height/cellSize; y++)
        {
            if (cells[x][y] == 1) {
                DrawRectangle(x * cellSize, y * cellSize, cellSize - 1, cellSize - 1, WHITE);
            } else {
                DrawRectangle(x * cellSize, y * cellSize, cellSize - 1, cellSize - 1, GRAY);
            }
           
        }
    }
}

void Grid::setCell(int x, int y, int value)
{
    if (x >= 0 && x < width/cellSize && y >= 0 && y < height/cellSize)
    {
        cells[x][y] = value;
    }
}

int Grid::getCellValue(int x, int y)
{
    if (x >= 0 && x < width/cellSize && y >= 0 && y < height/cellSize)
    {
        return cells[x][y];
    }
    return 0;
}

int Grid::getRows()
{
    return height/cellSize;
}

int Grid::getCols()
{
    return width/cellSize;
}
