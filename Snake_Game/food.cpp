#include "food.h"
#include "snake.h"

Food::Food(deque<point> snakeBody) {
    Image image = LoadImage("Graphics/apple1.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    pos = GenerateRandomPos(snakeBody);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() {
    DrawTexture(texture, offset + pos.x * cellsize, offset + pos.y * cellsize, WHITE);
}

point Food::GenerateRandomCell() {
    float x = GetRandomValue(0, cellcount - 1);
    float y = GetRandomValue(0, cellcount - 1);
    return point{ x, y };
}

point Food::GenerateRandomPos(deque<point> snakeBody) {
    point position = GenerateRandomCell();
    while (InDeque(position, snakeBody)) {
        position = GenerateRandomCell();
    }
    return position;
}
