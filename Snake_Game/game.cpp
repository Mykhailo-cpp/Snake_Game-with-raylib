#include "game.h"

Game::Game() : snake(), food(snake.body), state(RUNNING), score(0) {
    InitAudioDevice();
    eat = LoadSound("Sounds/eat.mp3");
    dead = LoadSound("Sounds/dead.mp3");
}

Game::~Game() {
    UnloadSound(eat);
    UnloadSound(dead);
    CloseAudioDevice();
}

void Game::Draw() {
    if (!state)
    {
        food.Draw();
        snake.Draw();
    }
    else if (state)
    {
        DrawGameOverScreen();
    }
    
}

void Game::Update() {
    if (state == 0) {
        snake.Update();
        Check();
        CheckEdges();
        CheckTail();
    }
}

void Game::Check() {
    if (snake.body[0].x == food.pos.x &&  snake.body[0].y == food.pos.y) {
        food.pos = food.GenerateRandomPos(snake.body);
        snake.add = true;
        score++;
        PlaySound(eat);
    }
}

void Game::CheckEdges() {
    if (snake.body[0].x == cellcount || snake.body[0].x == -1 || snake.body[0].y == cellcount || snake.body[0].y == -1) {
        GameOver();
    }
}

void Game::GameOver() {
    state = OVER;
    PlaySound(dead);
}

void Game::CheckTail() {
    deque<point> HeadLessBody = snake.body;
    HeadLessBody.pop_front();
    if (InDeque(snake.body[0], HeadLessBody)) {
        GameOver();
    }
}
void Game::DrawGameOverScreen()
{
    //offset - 5
      //  (2 * offset + cellsize * cellcount) / 2
    ClearBackground(BLACK);
    DrawText("Game Over", offset-5, (offset + cellsize * cellcount)/2-100, 100, RED);
    DrawText(TextFormat("Your score: %i", score), offset - 5, offset + cellsize * cellcount / 2, 100, RED);
}
