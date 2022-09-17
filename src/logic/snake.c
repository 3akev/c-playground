#include <unistd.h>
#include <stdlib.h>
#include "snake.h"

void add_segment(Snake *segment) {
    while(segment->next != NULL)
        segment = segment->next;

    // This is never freed before exiting the program, it's always needed
    Snake *segment2 = (Snake*) malloc(sizeof(Snake));
    segment2->position.x = segment->position.x;
    segment2->position.y = segment->position.y;
    segment->next = segment2;
}

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
    Point vector = Direction[gameState->snakeDirection];

    move_segments(&gameState->snakeHead);

    gameState->snakeHead.position.x += vector.x;
    gameState->snakeHead.position.y += vector.y;
}

void read_input(GameState *gameState) {
    char x;
    read(STDIN_FILENO, &x, 1);
    // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
    switch(x) {
        case 'w':
            gameState->snakeDirection = 0;
            break;
        case 'a':
            gameState->snakeDirection = 3;
            break;
        case 's':
            gameState->snakeDirection = 2;
            break;
        case 'd':
            gameState->snakeDirection = 1;
            break;
    }
}