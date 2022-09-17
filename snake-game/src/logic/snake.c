#include <unistd.h>
#include <stdlib.h>
#include "snake.h"

void add_segment(Snake *segment) {
    while(segment->next != NULL)
        segment = segment->next;

    // This is never freed before exiting the program, it's always needed while the program is running
    Snake *segment2 = (Snake*) malloc(sizeof(Snake));
    segment2->position.x = segment->position.x;
    segment2->position.y = segment->position.y;
    segment->next = segment2;
}

/* this moves each segment n to the position of segment n-1 in the linked list.
 * the segment given as an argument isn't moved. */
void move_segments(Snake *segment) {
    Point previousPosition, tmp;
    previousPosition = segment->position;

    while(segment->next != NULL) {
        segment = segment->next;
        tmp = segment->position;
        segment->position = previousPosition;
        previousPosition = tmp;
    }
}

void move_snake(GameState *gameState) {
    move_segments(&gameState->snakeHead);

    Point vector = Direction[gameState->snakeDirection];
    gameState->snakeHead.position.x += vector.x;
    gameState->snakeHead.position.y += vector.y;
}

void read_input(GameState *gameState) {
    char x;
    read(STDIN_FILENO, &x, 1);

    switch(x) {
        case 'w':
            gameState->snakeDirection = UP;
            break;
        case 'a':
            gameState->snakeDirection = LEFT;
            break;
        case 's':
            gameState->snakeDirection = DOWN;
            break;
        case 'd':
            gameState->snakeDirection = RIGHT;
            break;
    }
}