#include "consts.h"

int is_game_finished_diagonal(GameState gamestate)
{
}

int is_game_finished_horizontal(GameState gamestate)
{
    int i, j, player_i;
    for (player_i = 0; player_i < NUM_PLAYERS; player_i++)
        for (i = 0; i < GAME_WIDTH_TILES; i++)
        {
            int won = 1;
            for (j = 0; j < GAME_HEIGHT_TILES; j++)
                won = won && (gamestate[i][j] == Players[player_i]);

            if (won)
                return player_i + 1; // add one to 1-index players, zero being no one won.
        }
}

int is_game_finished_vertical(GameState gamestate)
{
    int i, j, player_i;
    for (player_i = 0; player_i < NUM_PLAYERS; player_i++)
        for (j = 0; j < GAME_HEIGHT_TILES; j++)
        {
            int won = 1;
            for (i = 0; i < GAME_WIDTH_TILES; i++)
                won = won && (gamestate[i][j] == Players[player_i]);

            if (won)
                return player_i + 1; // add one to 1-index players, zero being no one won.
        }
}

// this returns 0 if it's not finished, 1 if x won, 2 if o won
int is_game_finished(GameState gamestate)
{
    int result = 0;
    if (result = is_game_finished_vertical(gamestate))
        return result;
    else if (result = is_game_finished_horizontal(gamestate))
        return result;
    else if (result = is_game_finished_diagonal(gamestate))
        return result;
    else
        return result;
}