#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H

#include "../consts.h"

void read_input(GameState *gameState);

void move_snake(GameState *gameState);

void add_segment(Snake *snake);

#endif //SNAKE_GAME_SNAKE_H
