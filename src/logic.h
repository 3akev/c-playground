#ifndef SNAKE_GAME_LOGIC_H
#define SNAKE_GAME_LOGIC_H

#include "consts.h"

extern const Point Direction[4];

void read_input(Snake *snakeHead);

void move_snake(GameState *gameState);

#endif //SNAKE_GAME_LOGIC_H
