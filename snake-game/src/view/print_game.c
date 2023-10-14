#include "print_game.h"
#include "draw_game.h"
#include <stdio.h>

char horizontal_border[GAME_MAP_WIDTH + 3];

void initialise_printing() {
  int i;
  for (i = 0; i < GAME_MAP_WIDTH + 2; i++)
    horizontal_border[i] = '#';
  horizontal_border[i] = 0;
}

void print_horizontal_border() {
  printf("\033[47m" // white background
         "%s"
         "\033[m\n",
         horizontal_border);
}

void print_single_wall() {
  printf("\033[47m" // white background
         "#"
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
         "%c"
         "\033[m",
         color, ch);
}

void print_map(GameMap gameMap) {
  print_horizontal_border();
  int i, j;
  for (j = 0; j < GAME_MAP_HEIGHT; j++) {
    print_single_wall();
    for (i = 0; i < GAME_MAP_WIDTH; i++)
      print_char_with_color(gameMap[i][j]);
    print_single_wall();
    printf("\n");
  }
  print_horizontal_border();
}

void print_game(GameState *gameState) {
  printf("\e[1;1H\e[2J"); // clears the screen
  printf("Snake Game\n");

  redraw_game(gameState);
  print_map(gameState->gameMap);
}
