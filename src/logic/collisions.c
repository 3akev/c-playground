#include <stddef.h>
#include "collisions.h"
#include "snake.h"

void eat_apple(GameState *gameState) {
    gameState->apple = NULL;

    add_segment(&gameState->snakeHead);
}

void check_for_collisions(GameState *gameState) {
    Point vector = Direction[gameState->snakeHead.direction];
    Point newSnakePosition = gameState->snakeHead.position;
    newSnakePosition.x += vector.x;
    newSnakePosition.y += vector.y;

    if(newSnakePosition.x < 0 || newSnakePosition.x >= GAME_MAP_WIDTH || newSnakePosition.y < 0 || newSnakePosition.y >= GAME_MAP_HEIGHT) {
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