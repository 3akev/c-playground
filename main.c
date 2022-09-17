#include <stdio.h>
#include "consts.h"

void initialise_game(GameState gamestate)
{
    int i, j;
    for (i = 0; i < GAME_WIDTH_TILES; i++)
        for (j = 0; j < GAME_HEIGHT_TILES; j++)
            gamestate[i][j] = ' ';
}

void mainloop()
{
    while (1)
    {
    }
}

int main()
{
    printf("TicTacToe, I guess lol");
    GameState gamestate;
    initialise_game(gamestate);
    mainloop();
}