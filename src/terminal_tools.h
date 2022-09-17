#ifndef SNAKE_GAME_TERMINAL_TOOLS_H
#define SNAKE_GAME_TERMINAL_TOOLS_H

#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "terminal_tools.h"

void pause_for(int milliseconds);

void enableRawMode();

#endif //SNAKE_GAME_TERMINAL_TOOLS_H
