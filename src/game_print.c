#include <stdio.h>
#include <stdlib.h>
#include "game_print.h"

char* mult_char(char a, int x) {
    char *string;
    string = (char*)malloc(x*sizeof(char));
    int i;
    for(i=0;i<x;i++)
        string[i] = a;

    return string;
}

void print_map(GameMap gameMap) {
    char *horizontal_border = mult_char('#', GAME_MAP_WIDTH+2);
    printf("%s\n", horizontal_border);
    int i, j;
    for(j=0; j<GAME_MAP_HEIGHT; j++) {
        printf("#");
        for (i = 0; i < GAME_MAP_WIDTH; i++)
            printf("%c", gameMap[i][j]);
        printf("#\n");
    }
    printf("%s\n", horizontal_border);
    free(horizontal_border);
}

void clear_map(GameMap gameMap) {
    int i, j;
    for(i=0;i<GAME_MAP_WIDTH;i++)
        for(j=0;j<GAME_MAP_HEIGHT;j++)
            gameMap[i][j] = ' ';
}

void draw_snake(GameState *gameState) {
    Snake *segment = &gameState->snakeHead;
    while(segment != NULL) {
        int x = segment->position.x;
        int y = segment->position.y;
        gameState->gameMap[x][y] = 'o';
        segment = segment->next;
    }
}

void print_game(GameState *gameState) {
    printf("\e[1;1H\e[2J"); // clears the screen
    printf("Snake Game\n");

    clear_map(gameState->gameMap);

    draw_snake(gameState);

    print_map(gameState->gameMap);
}