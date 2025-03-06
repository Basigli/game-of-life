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
    SetTargetFPS(60);
    Simulator simulator(screenWidth, screenHeight, 20);
  


    while (!WindowShouldClose())
    {   
        BeginDrawing();
            ClearBackground(backgroundColor);
            simulator.draw();
        EndDrawing();
    }
    
    CloseWindow();
}