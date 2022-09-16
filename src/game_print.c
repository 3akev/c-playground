#include <stdio.h>
#include "game_print.h"

char horizontal_border[GAME_MAP_WIDTH + 3];

void initialise_printing() {
    int i;
    for (i = 0; i < GAME_MAP_WIDTH + 2; i++)
        horizontal_border[i] = '#';
    horizontal_border[i] = 0;
}

void print_map(GameMap gameMap) {
    printf("%s\n", horizontal_border);
    int i, j;
    for (j = 0; j < GAME_MAP_HEIGHT; j++) {
        printf("#");
        for (i = 0; i < GAME_MAP_WIDTH; i++)
            printf("%c", gameMap[i][j]);
        printf("#\n");
    }
    printf("%s\n", horizontal_border);
}

void clear_map(GameMap gameMap) {
    int i, j;
    for (i = 0; i < GAME_MAP_WIDTH; i++)
        for (j = 0; j < GAME_MAP_HEIGHT; j++)
            gameMap[i][j] = ' ';
}

void draw_snake(GameState *gameState) {
    Snake *segment = &gameState->snakeHead;
    while (segment != NULL) {
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