#include <sstream>
#include "raylib.h"
#include "Game.h"
#include "Player.h"

void PlayerInput(Game &game, int x, int y)
{
    if (game.getGameboardField(x, y) == game.EMPTYFIELD)
    {
        game.move(x, y);
        if (game.getGameState() == game.GAMERUNNING)
        {
            game.endTurn();
            game.aiMove();
        }
        if (game.getGameState() == game.GAMERUNNING)
        {
            game.endTurn();
        }       
    }
}

void DrawGameboard(Game &game)
{
    int x{0};
    int y{0};
    int width{200};
    int height{200};
    Color color;
    Vector2 mousePos = GetMousePosition();

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

            DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
            x += width + 2;
        }
        y += height + 2;
        x = 0;
    }
}

int main()
{
    //setup game
    Game game = Game();
    const Player playerOne(1, "Player One", false);
    const Player playerTwo(2, "Computer", true);
    std::array<Player, 2> players = {playerOne, playerTwo};
    game.setPlayers(players);
    game.startGame();

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

        BeginDrawing();
        ClearBackground(WHITE);
        DrawGameboard(game);
        std::string displayText;
        std::string winningPlayerName;
        switch (game.getGameState())
        {
        case game.PLAYERWON:
            winningPlayerName = game.getActivePlayer().getNumber() == playerOne.getNumber() ? playerOne.getName() : playerTwo.getName();
            displayText = winningPlayerName + " wins!";
            break;
        case game.GAMEDRAW:
            displayText = "Game is draw!";
            break;
        }
        if (game.getGameState() != game.GAMERUNNING)
        {
            DrawText(displayText.c_str(), 620, 300, 20, RED);
            if (IsMouseButtonPressed(0))
            {
                game.stopGame();
                game.startGame();
            }
        }
        EndDrawing();
    }
    CloseWindow();
}