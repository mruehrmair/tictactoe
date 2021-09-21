#include <sstream>
#include "raylib.h"
#include "Game.h"
#include "Player.h"

<<<<<<< HEAD
void PlayerInput(Game &game, int x, int y)
{
    if (game.getGameboardField(x, y) == game.EMPTYFIELD)
    {
        game.move(x, y);
        game.endTurn();
        if (game.getGameState() == 1)
        {
            game.aiMove();
            game.endTurn();
        }
    }
}

void DrawGameboard(Game &game)
=======
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
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e
{
    int x{0};
    int y{0};
    int width{200};
    int height{200};
<<<<<<< HEAD
    Color color;
    Vector2 mousePos = GetMousePosition();
=======
    Color color = GRAY;
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e

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

<<<<<<< HEAD
            switch (field)
            {
            case game.EMPTYFIELD:
                color = GRAY;
                break;
            case 1:
                color = BLUE;
                break;
            case 2:
                color = RED;
            }

            if (CheckCollisionPointRec(mousePos, rec) && IsMouseButtonReleased(0))
            {
                PlayerInput(game, i, j);
            }

=======
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
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e
            DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
            x += width + 2;
        }
        y += height + 2;
        x = 0;
    }
}

int main()
{
<<<<<<< HEAD
    //setup game
=======
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e
    Game game = Game();
    const Player playerOne(1, "Player One", false);
    const Player playerTwo(2, "Computer", true);
    std::array<Player, 2> players = {playerOne, playerTwo};
    game.setPlayers(players);
<<<<<<< HEAD
    game.startGame();
=======
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e

    //window dimensions
    int width{800};
    int height{600};
    // int windowStart{0};

    //settings
    int targetFPS{30};
    // int speed{10};
    // int direction{10};
    // int fontSize{20};
    SetTargetFPS(targetFPS);
    InitWindow(width, height, "TicTacToe");

    while (!WindowShouldClose())
    {
        //begin game logic

        //draw player info panel
        /*  std::stringstream playerName;
        playerName << "Player name:" << std::endl << playerOne.getName();
        DrawText(playerName.str().c_str(),650,300,20,RED); */
        //
<<<<<<< HEAD
=======
        DrawGameboard(game);
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e

        BeginDrawing();
        ClearBackground(WHITE);
        DrawGameboard(game);
        switch (game.getGameState())
        {
        case game.PLAYERWON:
            game.stopGame();
            DrawText("Game over!", 650, 300, 20, RED);
            break;
        case game.GAMEDRAW:
            game.stopGame();
            DrawText("Draw!", 650, 300, 20, RED);
            break;
        }

        /* while (!(game.getGameState() == game.GAMEEND))
        {
        } */
        EndDrawing();
    }
<<<<<<< HEAD
    CloseWindow();
=======
>>>>>>> 5eb4c6cab29908af7c1d454fd12f7cc6661eff4e
}