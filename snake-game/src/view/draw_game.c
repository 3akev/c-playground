#include "draw_game.h"
#include "../consts.h"
#include <stddef.h>

void clear_map(GameMap gameMap) {
  int i, j;
  for (i = 0; i < mapWidth; i++)
    for (j = 0; j < mapHeight; j++)
      gameMap[i][j] = ' ';
}

void draw_snake(GameState *gameState) {
  Snake *segment = gameState->snakeHead;
  while (segment != NULL) {
    gameState->gameMap[segment->position.x][segment->position.y] =
        SNAKE_DISPLAY_CHAR;
    segment = segment->next;
  }
}

void draw_apple(GameState *gameState) {
  gameState->gameMap[gameState->apple->x][gameState->apple->y] =
      APPLE_DISPLAY_CHAR;
}

// this redraws the map buffer in-memory, so it doesn't print anything
void redraw_game(GameState *gameState) {
  clear_map(gameState->gameMap);
  draw_apple(gameState);
  draw_snake(gameState);
}
