#include <raylib.h>
#include <vector>
#include <cstdlib> // For srand and time
#include <ctime>   // For time
#include "simulator.hpp"

int main() 
{
    const Color backgroundColor = {252, 208, 161};
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    


    InitWindow(screenWidth, screenHeight, "Game of Life");
    SetTargetFPS(5);
    Simulator simulator(screenWidth, screenHeight, 20);
    
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
   simulator.setCellAlive(10, 10);
   simulator.setCellAlive(11, 10);
   simulator.setCellAlive(12, 10);



    while (!WindowShouldClose())
    {   
        simulator.updateStatus();
        BeginDrawing();
            ClearBackground(backgroundColor);
            simulator.draw();
        EndDrawing();
    }
    
    CloseWindow();
}