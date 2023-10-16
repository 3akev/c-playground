#include <stdio.h>
#include "consts.h"
#include "win_check.c"
#include "game_print.c"

void make_move(GameState gamestate, int choice, char player)
{
    // reverse through the calculation used to enumerate each box, which is
    // (3*j + i + 1)
    // to obtain the correct indices
    choice--;
    int j = choice / 3;
    int i = choice - 3 * j;

    gamestate[i][j] = player;
}

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
    int player_index = 1;
    while (!(winner = is_game_finished(gamestate)))
    {
        player_index = !player_index;
        print_game(gamestate);

        int choice;
        receive_player_input(player_index, &choice);

        if (choice >= 1 && choice <= 9)
            make_move(gamestate, choice, Players[player_index]);
        else
            player_index = !player_index; // if invalid input, flip player index twice to remain with the same player
    }
    print_game(gamestate);
    if (winner > 0 && winner <= NUM_PLAYERS)
        printf("Player %c won the game!\n", Players[player_index]);
    else
        printf("It's a draw!\n");
}

int main()
{
    GameState gamestate;
    initialise_game(gamestate);
    mainloop(gamestate);
    return 0;
}