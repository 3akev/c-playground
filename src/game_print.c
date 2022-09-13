#include <stdio.h>
#include <stdlib.h>
#include "consts.h"

char* mult_char(char a, int x) {
    char *string;
    string = (char*)malloc(x*sizeof(char));
    int i;
    for(i=0;i<x;i++)
        string[i] = a;

    return string;
}

void print_game(GameMap gameMap) {
    printf("\e[1;1H\e[2J"); // clears the screen
    printf("Snake Game\n");

    char *horizontal_border = mult_char('#', GAME_MAP_WIDTH+2);
    printf("%s\n", horizontal_border);
    int i, j;
    for(j=0; j<GAME_MAP_HEIGHT; j++) {
        printf("#");
        for (i = 0; i < GAME_MAP_WIDTH; i++)
            printf("%c", gameMap[i][j]);
        printf("#\n");
    }
    printf("%s", horizontal_border);
}