#include <stdio.h>
#include <unistd.h>
#include "snake.h"

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

void read_input(Snake *snakeHead) {
    char x;
    read(STDIN_FILENO, &x, 1);
    // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
    switch(x) {
        case 'w':
            snakeHead->direction = 0;
            break;
        case 'a':
            snakeHead->direction = 3;
            break;
        case 's':
            snakeHead->direction = 2;
            break;
        case 'd':
            snakeHead->direction = 1;
            break;
    }
}