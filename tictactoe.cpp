#include <sstream>
#include "raylib.h"
#include "Game.h"
#include "Player.h"

struct Field
{
    int width;
    int height;
    int x;
    int y;
    Color color;
    Rectangle rec;
};

void DrawGameboard(Field matrix[][3], int size)
{
    int x{0};
    int y{0};
    Vector2 mousePos = GetMousePosition();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Rectangle rec{
                static_cast<float>(matrix[i][j].x + x),
                static_cast<float>(matrix[i][j].y + y),
                static_cast<float>(matrix[i][j].width),
                static_cast<float>(matrix[i][j].height)};

            matrix[i][j].rec = rec;

            if (CheckCollisionPointRec(mousePos, matrix[i][j].rec) && IsMouseButtonDown(0))
            {
                matrix[i][j].color = RED;
            }
            else if (CheckCollisionPointRec(mousePos, matrix[i][j].rec) && IsMouseButtonDown(1))
            {
                matrix[i][j].color = BLUE;
            }
            DrawRectangle(rec.x, rec.y, rec.width, rec.height, matrix[i][j].color);
            x += matrix[i][j].width + 2;
        }
        y += matrix[i][0].height + 2;
        x = 0;
    }
}

/* int main()
{
    Player playerOne(1,"Markis");
    Player playerTwo(2,"Ela");
    Game game = Game();
    game.move(playerOne,2,2);
    //window dimensions
    int width{800};
    int height{600};
    // int windowStart{0};

    //init fields
    const int size = game.SIZE;
    Field gameboard[size][size];
    Field emptyField{200, 200, 0, 0, GRAY};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            gameboard[i][j] = emptyField;
        }
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
        //draw player info panel
        std::stringstream playerName;
        playerName << "Player name:" << std::endl << playerOne.getName();
        DrawText(playerName.str().c_str(),650,300,20,RED);
        //
        DrawGameboard(gameboard, size);

        EndDrawing();
    }
} */