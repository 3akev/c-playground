#include "consts.h"
#include "logic/apple.h"
#include "logic/collisions.h"
#include "logic/snake.h"
#include "view/draw_game.h"
#include "view/input.h"
#include "view/print_game.h"
#include "view/terminal_tools.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int playSpeed = 100;
int mapWidth = 16;
int mapHeight = 16;

void initialise_game_state(GameState *gameState) {
  gameState->score = 0;
  gameState->isAlive = 1;
  gameState->apple = NULL;

  // place snake in middle with random starting direction
  gameState->snakeHead = malloc(sizeof(Snake));
  gameState->snakeHead->position.x = mapWidth / 2;
  gameState->snakeHead->position.y = mapHeight / 2;
  gameState->snakeHead->next = gameState->snakeTail;
  gameState->snakeHead->prev = NULL;

  gameState->snakeTail = malloc(sizeof(Snake));
  gameState->snakeTail->position.x = mapWidth / 2;
  gameState->snakeTail->position.y = mapHeight / 2;
  gameState->snakeTail->next = NULL;
  gameState->snakeTail->prev = gameState->snakeHead;

  srand(time(NULL));
  gameState->snakeDirection = rand() % 4;

  gameState->gameMap = malloc(mapWidth * sizeof(char *));
  for (int i = 0; i < mapWidth; i++)
    gameState->gameMap[i] = malloc(mapHeight * sizeof(char));
}

void free_game_state(GameState *gameState) {
  free_apple();

  free_snake(gameState);
  for (int i = 0; i < mapWidth; i++)
    free(gameState->gameMap[i]);
  free(gameState->gameMap);
}

void mainloop(GameState *gameState) {
  while (gameState->isAlive) {
    pause_for(playSpeed);
    read_input(gameState);
    check_for_collisions(gameState);
    if (gameState->isAlive)
      move_snake(gameState);
    if (gameState->apple == NULL)
      place_apple(gameState);
    print_game(gameState);
  }
  free_game_state(gameState);
  printf("GAME OVER!\n");
}

int main(int argc, char **argv) {
  const char *helpstr = ("usage: %s [options]\n"
                         "options:\n"
                         "\t-h: print help\n"
                         "\t-s: set game speed (default 1)\n"
                         "\t-d: set map width x height (default 16 x 16)\n");

  int optchar;
  while ((optchar = getopt(argc, argv, "hs:d:")) != -1) {
    switch (optchar) {
    case 'h':
      printf(helpstr, argv[0]);
      exit(0);
    case 's':
      playSpeed = (int)(100 / atof(optarg));
      break;
    case 'd':
      sscanf(optarg, "%d x %d", &mapWidth, &mapHeight);
      break;
    }
  }

  GameState gameState;

  enableRawMode();

  initialise_game_state(&gameState);
  clear_map(gameState.gameMap);

  mainloop(&gameState);
}
