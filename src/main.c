#include <stdio.h>
#include "consts.h"
#include "win_check.c"

void initialise_game(GameState gamestate)
{
    int i, j;
    for (j = 0; j < GAME_HEIGHT_TILES; j++)
        for (i = 0; i < GAME_WIDTH_TILES; i++)
            gamestate[i][j] = ' ';
}

void mainloop(GameState gamestate)
{
    while (is_game_finished(gamestate))
    {
    }
}

int main()
{
    printf("TicTacToe, I guess lol\n");
    GameState gamestate;
    initialise_game(gamestate);
    mainloop(gamestate);
}