#include "snake.h"

Snake::Snake() : body({ point{6, 9}, point{5, 9}, point{4, 9} }), direction{ 1, 0 }, add(false) {}

void Snake::Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
        int x = body[i].x;
        int y = body[i].y;
        Rectangle segment = { offset + x * cellsize, offset + y * cellsize, cellsize, cellsize };
        DrawRectangleRounded(segment, 0.7, 6, darkGreen);
    }
}

void Snake::Update() {
    body.push_front({ body[0].x + direction.x, body[0].y + direction.y });
    if (add) {
        add = false;
    }
    else {
        body.pop_back();
    }
}

void Snake::Reset() {
    body = { point{6, 9}, point{5, 9}, point{4, 9} };
    direction = { 1, 0 };
}

bool InDeque(point element, deque<point> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (deque[i].x == element.x &&  deque[i].y == element.y)
        {
            return true;
        }
    }
    return false;
}
