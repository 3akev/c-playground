#include <stdio.h>
#include "consts.h"

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}

void print_game_state(GameState gamestate)
{
    int i, j;
    for (j = 0; j < GAME_HEIGHT_TILES; j++)
    {
        for (i = 0; i < GAME_WIDTH_TILES; i++)
        {
            // if the box is empty, print its number instead for player choice
            char to_print = gamestate[i][j] != ' ' ? gamestate[i][j] : (3 * j + i + 1) + '0';
            printf("| %c ", to_print);
        }
        printf("|\n");
    }
}