#include "raylib.h"

int main()
{
    //window dimensions
    int width{800};
    int height{600};
    // int windowStart{0};

    //settings
    int targetFPS{60};
    // int speed{10};
    // int direction{10};
    // int fontSize{20};
    SetTargetFPS(targetFPS);
    InitWindow(width, height, "Markus' Window!");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    
}