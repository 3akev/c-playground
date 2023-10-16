#include "print_game.h"
#include "../consts.h"
#include "draw_game.h"
#include <stdio.h>
#include <stdlib.h>

void print_horizontal_border() {
  printf("\033[47m"); // white background
  int i;
  for (i = 0; i < 2 * (mapWidth + 2); i++)
    printf("#");
  printf("\033[m\n");
}

void print_single_wall() {
  printf("\033[47m" // white background
         " #"
         "\033[m");
}

void print_char_with_color(char ch) {
  char color;

  switch (ch) {
  case SNAKE_DISPLAY_CHAR:
    color = 32; // green
    break;
  case APPLE_DISPLAY_CHAR:
    color = 31; // red
    break;
  default:
    color = 0; // white
  };

  printf("\033[%dm"
         " %c"
         "\033[m",
         color, ch);
}

void print_map(GameMap gameMap) {
  print_horizontal_border();
  int i, j;
  for (j = 0; j < mapHeight; j++) {
    print_single_wall();
    for (i = 0; i < mapWidth; i++)
      print_char_with_color(gameMap[i][j]);
    print_single_wall();
    printf("\n");
  }
  print_horizontal_border();
}

void print_game(GameState *gameState) {
  printf("\e[1;1H\e[2J"); // clears the screen
  printf("Snake Game\tScore : %ld\n", gameState->score);

  redraw_game(gameState);
  print_map(gameState->gameMap);
}
