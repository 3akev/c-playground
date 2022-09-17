#include "consts.h"

int is_game_finished_diagonal(GameState gamestate)
{
}

int is_game_finished_horizontal(GameState gamestate)
{
}

int is_game_finished_vertical(GameState gamestate)
{
}

// this returns 0 if it's not finished, 1 if x won, 2 if o won
int is_game_finished(GameState gamestate)
{
    return is_game_finished_vertical(gamestate) || is_game_finished_horizontal(gamestate) || is_game_finished_diagonal(gamestate);
}