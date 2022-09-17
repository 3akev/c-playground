#include <stdlib.h>
#include <time.h>
#include "apple.h"

Point emptyPointsArray[GAME_MAP_WIDTH*GAME_MAP_HEIGHT];

// this fills the array declared above with empty points, returning the last valid index
short get_empty_points(GameState *gameState) {
    short idx = 0;

    char i, j;
    for(i=0; i<GAME_MAP_WIDTH; i++)
        for(j=0;j<GAME_MAP_HEIGHT; j++)
            if (gameState->gameMap[i][j] == ' ') {
                Point p = {i, j};
                emptyPointsArray[idx++] = p;
            }

    return --idx;
}

void place_apple(GameState *gameState) {
    short length = get_empty_points(gameState);

    srand(time(NULL));
    short idx = rand() % (length + 1);

    gameState->apple = emptyPointsArray + idx;
}