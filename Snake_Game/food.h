#ifndef FOOD_H
#define FOOD_H

#include <deque>
#include <raylib.h>
#define point pair<int, int>
using namespace std;

extern int cellsize;
extern int cellcount;
extern int offset;

class Food {
public:
    point pos;
    Texture2D texture;
    Food(deque<point> snakeBody);
    ~Food();
    void Draw();
    point GenerateRandomCell();
    point GenerateRandomPos(deque<point> snakeBody);
};

#endif
