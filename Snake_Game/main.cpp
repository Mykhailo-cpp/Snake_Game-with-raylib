#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

float speed = 0.2;

Color green = { 173, 204, 96, 255 };

Color darkGreen = { 43, 51, 24, 255 };

int cellsize = 30;

int cellcount = 25;

int offset = 75;

double lastUpdate = 0;

bool update(double interval)
{
    double curT = GetTime();
    if (curT - lastUpdate >= interval)
    {
        lastUpdate = curT;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(2 * offset + cellsize * cellcount, 2 * offset + cellsize * cellcount, "Snake Game");
    SetTargetFPS(60);
    Game game = Game();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);
        if (update(speed)) {
            game.Update();
        }
        if (game.state == 0)
        {
            if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
                game.snake.direction = { 0, -1 };
                game.state = RUNNING;
            }
            if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
                game.snake.direction = { 0, 1 };
                game.state = RUNNING;
            }
            if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
                game.snake.direction = { -1, 0 };
                game.state = RUNNING;
            }
            if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
                game.snake.direction = { 1, 0 };
                game.state = RUNNING;
            }
            DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellsize * cellcount + 10, (float)cellsize * cellcount + 10 }, 5, darkGreen);
            DrawText("Snake Game, press any arrow to play", offset - 5, 20, 40, darkGreen);
            DrawText(TextFormat("%i", game.score), offset - 5, offset + cellsize * cellcount + 10, 40, darkGreen);
        }
        game.Draw();
        if (game.state == OVER && IsKeyPressed(KEY_SPACE)) {
            game.snake.Reset();
            game.food.pos = game.food.GenerateRandomPos(game.snake.body);
            game.state = RUNNING;
            game.score = 0;
            speed = 0.2;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
