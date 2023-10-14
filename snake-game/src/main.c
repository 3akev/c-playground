#include "consts.h"
#include "logic/apple.h"
#include "logic/collisions.h"
#include "logic/snake.h"
#include "view/draw_game.h"
#include "view/input.h"
#include "view/print_game.h"
#include "view/terminal_tools.h"
#include <stdio.h>

void initialise_game_state(GameState *gameState) {
  gameState->isAlive = 1;
  gameState->apple = NULL;

  // place snake in middle with random starting direction
  gameState->snakeHead = malloc(sizeof(Snake));
  gameState->snakeHead->position.x = GAME_MAP_WIDTH / 2;
  gameState->snakeHead->position.y = GAME_MAP_HEIGHT / 2;
  gameState->snakeHead->next = gameState->snakeTail;
  gameState->snakeHead->prev = NULL;

  gameState->snakeTail = malloc(sizeof(Snake));
  gameState->snakeTail->position.x = GAME_MAP_WIDTH / 2;
  gameState->snakeTail->position.y = GAME_MAP_HEIGHT / 2;
  gameState->snakeTail->next = NULL;
  gameState->snakeTail->prev = gameState->snakeHead;

  srand(time(NULL));
  gameState->snakeDirection = rand() % 4;
}

void mainloop(GameState *gameState) {
  while (gameState->isAlive) {
    pause_for(100);
    read_input(gameState);
    check_for_collisions(gameState);
    if (gameState->isAlive)
      move_snake(gameState);
    if (gameState->apple == NULL)
      place_apple(gameState);
    print_game(gameState);
  }
  free_snake(gameState);
  printf("GAME OVER!\n");
}

int main() {
  GameState gameState;

  enableRawMode();

  initialise_game_state(&gameState);
  initialise_printing();
  clear_map(gameState.gameMap);

  mainloop(&gameState);
}
