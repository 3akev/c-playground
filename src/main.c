#include <stdio.h>
#include "consts.h"
#include "win_check.c"
#include "game_print.c"

void initialise_game(GameState gamestate)
{
    int i, j;
    for (j = 0; j < GAME_HEIGHT_TILES; j++)
        for (i = 0; i < GAME_WIDTH_TILES; i++)
            gamestate[i][j] = ' ';
}

void mainloop(GameState gamestate)
{
    int winner = 0;
    while (!(winner = is_game_finished(gamestate)))
    {
        clear_screen();
        printf("Tic-Tac-Toe\n");
        print_game_state(gamestate);

        int choice;
        printf("Choose your move(1-9): ");
        scanf("%d", &choice);
    }
}

int main()
{
    GameState gamestate;
    initialise_game(gamestate);
    mainloop(gamestate);
}