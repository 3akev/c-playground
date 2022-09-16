#include <stdio.h>
#include "game_print.h"

char horizontal_border[GAME_MAP_WIDTH + 3];

void initialise_printing() {
    int i;
    for (i = 0; i < GAME_MAP_WIDTH + 2; i++)
        horizontal_border[i] = '#';
    horizontal_border[i] = 0;
}

void print_horizontal_border() {
    printf("\033[47m"
           "%s"
           "\033[m\n", horizontal_border);
}

void print_single_wall() {
    printf("\033[47m"
           "#"
           "\033[m");
}

void print_map(GameMap gameMap) {
    print_horizontal_border();
    int i, j;
    for (j = 0; j < GAME_MAP_HEIGHT; j++) {
        print_single_wall();
        for (i = 0; i < GAME_MAP_WIDTH; i++)
            printf("%c", gameMap[i][j]);
        print_single_wall();
        printf("\n");
    }
    print_horizontal_border();
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