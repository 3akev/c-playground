#include <stdio.h>
#include "consts.h"

void print_game_state(GameState gamestate)
{
    int i, j;
    for (j = 0; j < GAME_HEIGHT_TILES; j++)
    {
        for (i = 0; i < GAME_WIDTH_TILES; i++)
        {
            // if the box is empty, print its number instead for player choice
            // we add the char '0' to convert the resulting int to the corresponding ascii character
            char to_print = gamestate[i][j] != ' ' ? gamestate[i][j] : (3 * j + i + 1) + '0';
            printf("| %c ", to_print);
        }
        printf("|\n");
    }
}

void print_game(GameState gamestate, int player_index)
{
    printf("\e[1;1H\e[2J"); // clears the screen
    printf("Tic-Tac-Toe\n");
    print_game_state(gamestate);
    printf("[%c] Choose your move(1-9): ", Players[player_index]);
}