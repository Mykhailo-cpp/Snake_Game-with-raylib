#ifndef GAME_H
#define GAME_H

#include <deque>
#include <raylib.h>
#include "snake.h"
#include "food.h"
using namespace std;
enum GameState
{
    RUNNING,
    OVER
};

class Game {
public:
    Snake snake;
    Food food;
    GameState state;
    int score;
    Sound eat;
    Sound dead;
    Game();
    ~Game();
    void Draw();
    void Update();
    void Check();
    void CheckEdges();
    void GameOver();
    void CheckTail();
    void DrawGameOverScreen();
};
#endif

