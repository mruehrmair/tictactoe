#include "raylib.h"

struct Field
{
    int width;
    int height;
    int x;
    int y;
    Color color;
};

void DrawMatrix(Field *matrix, int size)
{
    int x{0};
    int y{0};
    for (int i = 0; i < size; i++)
    {
        DrawRectangle(matrix[i].x + x, matrix[i].y + y, matrix[i].width, matrix[i].height, matrix[i].color);
        x += matrix[i].width + 2;
        bool newLine = !((i + 1) % 3);
        if (newLine)
        {
            y += matrix[i].height + 2;
            x = 0;
        }
    }
}

int main()
{
    //window dimensions
    int width{800};
    int height{600};
    // int windowStart{0};

    //init fields
    const int matrixSize{9};
    Field matrix[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i].width = 200;
        matrix[i].height = 200;
        matrix[i].x = 0;
        matrix[i].y = 0;
        matrix[i].color = RED;
    }
    //settings
    int targetFPS{60};
    // int speed{10};
    // int direction{10};
    // int fontSize{20};
    SetTargetFPS(targetFPS);
    InitWindow(width, height, "TicTacToe");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        //begin game logic
        DrawMatrix(matrix, matrixSize);
        EndDrawing();
    }
}