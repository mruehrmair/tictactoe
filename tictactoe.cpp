#include <sstream>
#include "raylib.h"
#include "Game.h"
#include "Player.h"

/* struct Field
{
    int width;
    int height;
    int x;
    int y;
    Color color;
    Rectangle rec;
};
 */
void DrawGameboard(Game const &game)
{
    int x{0};
    int y{0};
    int width{200};
    int height{200};
    Color color = GRAY;

    for (int i = 0; i < game.SIZE; i++)
    {
        for (int j = 0; j < game.SIZE; j++)
        {
            int field = game.getGameboardField(i, j);
            Rectangle rec{
                static_cast<float>(0 + x),
                static_cast<float>(0 + y),
                static_cast<float>(width),
                static_cast<float>(height)};

            if (field == 1)
            {
                color = BLUE;
            }
            if (field == 2)
            {
                color = RED;
            }
            /*
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, rec) && IsMouseButtonDown(0))
            {
                color = RED;
            }
            else if (CheckCollisionPointRec(mousePos, rec) && IsMouseButtonDown(1))
            {
                color = BLUE;
            } */
            DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
            x += width + 2;
        }
        y += height + 2;
        x = 0;
    }
}

int main()
{
    Game game = Game();
    const Player playerOne(1, "Player One", false);
    const Player playerTwo(2, "Computer", true);
    std::array<Player, 2> players = {playerOne, playerTwo};
    game.setPlayers(players);

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
    InitWindow(width, height, "TicTacToe");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        //begin game logic
        //draw player info panel
        /*  std::stringstream playerName;
        playerName << "Player name:" << std::endl << playerOne.getName();
        DrawText(playerName.str().c_str(),650,300,20,RED); */
        //
        DrawGameboard(game);

        EndDrawing();
    }
}