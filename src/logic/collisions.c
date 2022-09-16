#include <malloc.h>
#include "collisions.h"

void eat_apple(GameState *gameState) {
    free(gameState->apple);
    gameState->apple = NULL;

    // grow snake
    Snake *segment = gameState->snakeHead.next;
    while(segment->next != NULL)
        segment = segment->next;

    Snake *segment2 = (Snake*) malloc(sizeof(Snake));
    segment2->position.x = segment->position.x;
    segment2->position.y = segment->position.y;
    segment->next = segment2;
}

void check_for_collisions(GameState *gameState) {
    Point vector = Direction[gameState->snakeHead.direction];
    Point newSnakePosition = gameState->snakeHead.position;
    newSnakePosition.x += vector.x;
    newSnakePosition.y += vector.y;

    if(newSnakePosition.x < 0 || newSnakePosition.x > GAME_MAP_WIDTH || newSnakePosition.y < 0 || newSnakePosition.y > GAME_MAP_HEIGHT) {
        gameState->isAlive = 0;
        return;
    }

    char x = gameState->gameMap[newSnakePosition.x][newSnakePosition.y];
    if(x == SNAKE_DISPLAY_CHAR) {
        gameState->isAlive = 0;
        return;
    } else if(x == APPLE_DISPLAY_CHAR) {
        eat_apple(gameState);
    }
}