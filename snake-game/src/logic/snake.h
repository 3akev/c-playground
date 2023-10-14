#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H

#include "../consts.h"

void read_input(GameState *gameState);

void move_snake(GameState *gameState);

void add_segment(GameState *gameState);

void free_snake(GameState *gameState);

#endif // SNAKE_GAME_SNAKE_H
