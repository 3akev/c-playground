#include <stdio.h>
#include "consts.h"

void print_game(GameMap gameMap) {
    printf("\e[1;1H\e[2J"); // clears the screen
    printf("Snake Game\n");
    int i, j;
    for(j=0; j<GAME_MAP_HEIGHT; j++) {
        for (i = 0; i < GAME_MAP_WIDTH; i++)
            printf("%c", gameMap[i][j]);
        printf("\n");
    }
}