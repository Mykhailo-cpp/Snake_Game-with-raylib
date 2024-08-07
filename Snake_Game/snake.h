#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <raylib.h>
using namespace std;
#define point pair<int, int>
#define x first
#define y second
extern int cellsize;
extern int cellcount;
extern int offset;
extern Color darkGreen;

class Snake {
public:
    deque<point> body;
    point direction;
    bool add;
    Snake();
    void Draw();
    void Update();
    void Reset();
};

bool InDeque(point element, deque<point> deque);

#endif

