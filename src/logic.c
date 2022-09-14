#include <stdlib.h>
#include "logic.h"

// 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
const Point Direction[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void move_segments(Snake *segment) {
    Point currentSegmentPos, nextSegmentPos;
    currentSegmentPos = segment->position;

    while(segment->next != NULL) {
        segment = segment->next;
        nextSegmentPos = segment->position;
        segment->position = currentSegmentPos;
        currentSegmentPos = nextSegmentPos;
    }
}

void move_snake(GameState *gameState) {
    Point vector = Direction[gameState->snakeHead.direction];

    move_segments(&gameState->snakeHead);

    gameState->snakeHead.position.x += vector.x;
    gameState->snakeHead.position.y += vector.y;
}