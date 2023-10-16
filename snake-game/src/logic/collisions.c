#include "collisions.h"
#include "../consts.h"
#include "snake.h"
#include <stddef.h>

const Point Direction[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int is_out_of_bounds(Point *position) {
  return (*position).x < 0 || (*position).x >= mapWidth || (*position).y < 0 ||
         (*position).y >= mapHeight;
}

void check_for_collisions(GameState *gameState) {
  Point vector = Direction[gameState->snakeDirection];
  Point newSnakePosition = gameState->snakeHead->position;
  newSnakePosition.x += vector.x;
  newSnakePosition.y += vector.y;

  if (is_out_of_bounds(&newSnakePosition)) {
    gameState->isAlive = 0;
    return;
  }

  char x = gameState->gameMap[newSnakePosition.x][newSnakePosition.y];
  if (x == SNAKE_DISPLAY_CHAR) {
    gameState->isAlive = 0;

  } else if (x == APPLE_DISPLAY_CHAR) {
    gameState->apple = NULL;
    gameState->score += 1000;
    add_segment(gameState);
  }

  // points for not dying
  gameState->score += 1;
}
