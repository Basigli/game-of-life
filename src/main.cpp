#include <raylib.h>
#include <vector>
#include <cstdlib> // For srand and time
#include <ctime>   // For time
#include "simulator.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() 
{
    const Color backgroundColor = {252, 208, 161};
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    constexpr int cellSize = 20;

    bool isRunning = false;
    InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(20);
    Simulator simulator(screenWidth, screenHeight, cellSize);
    
    /*
    simulator.setCellAlive(11, 10);
    simulator.setCellAlive(10, 11);
    simulator.setCellAlive(11, 11);
    simulator.setCellAlive(12, 11);
    simulator.setCellAlive(13, 11);
    simulator.setCellAlive(10, 12);
    simulator.setCellAlive(11, 12);
    simulator.setCellAlive(13, 12);
    simulator.setCellAlive(14, 12);
    */
   srand(time(0));

   for (int x = 0; x <= screenWidth/cellSize; x++)
   {
       for (int y = 0; y <= screenHeight/cellSize; y++)
       {
            if (rand() % 2 == 1)
                simulator.setCellAlive(x, y);

       }
   }

    while (!WindowShouldClose())
    {   
        if (GuiButton((Rectangle){10, 10, 100, 20}, isRunning ? "Stop" : "Start"))  
        {
            isRunning = !isRunning;
        }
        if (isRunning) {
            simulator.updateStatus();
        }
      
        BeginDrawing();
            ClearBackground(backgroundColor);
            simulator.draw();
            GuiButton((Rectangle){10, 10, 100, 20}, isRunning ? "Stop" : "Start");
        EndDrawing();
    }
    
    CloseWindow();
}