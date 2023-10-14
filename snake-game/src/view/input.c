#include "input.h"
#include <unistd.h>

void read_input(GameState *gameState) {
  char x;
  read(STDIN_FILENO, &x, 1);

  switch (x) {
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
