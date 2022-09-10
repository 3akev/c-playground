#include "consts.h"

int is_game_finished_antidiagonal(GameState gamestate)
{
    int player_index;
    for (player_index = 0; player_index < NUM_PLAYERS; player_index++)
    {
        char player = Players[player_index];
        if (player == gamestate[2][0] && player == gamestate[1][1] && player == gamestate[0][2])
            return player_index + 1; // add one to 1-index players, zero being no one won.
    }
    return 0;
}

int is_game_finished_diagonal(GameState gamestate)
{
    int player_index;
    for (player_index = 0; player_index < NUM_PLAYERS; player_index++)
    {
        char player = Players[player_index];
        if (player == gamestate[0][0] && player == gamestate[1][1] && player == gamestate[2][2])
            return player_index + 1; // add one to 1-index players, zero being no one won.
    }
    return 0;
}

int is_game_finished_horizontal(GameState gamestate)
{
    int i, j, player_index;
    for (player_index = 0; player_index < NUM_PLAYERS; player_index++)
        for (i = 0; i < GAME_WIDTH_TILES; i++)
        {
            int won = 1;
            for (j = 0; j < GAME_HEIGHT_TILES; j++)
                won = won && (gamestate[i][j] == Players[player_index]);

            if (won)
                return player_index + 1; // add one to 1-index players, zero being no one won.
        }

    return 0;
}

int is_game_finished_vertical(GameState gamestate)
{
    int i, j, player_index;
    for (player_index = 0; player_index < NUM_PLAYERS; player_index++)
        for (j = 0; j < GAME_HEIGHT_TILES; j++)
        {
            int won = 1;
            for (i = 0; i < GAME_WIDTH_TILES; i++)
                won = won && (gamestate[i][j] == Players[player_index]);

            if (won)
                return player_index + 1; // add one to 1-index players, zero being no one won.
        }

    return 0;
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
    else if (result = is_game_finished_antidiagonal(gamestate))
        return result;
    else
        return result;
}