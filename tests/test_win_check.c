#include "minunit.h"
#include "../src/consts.h"
#include "../src/win_check.c"

#define TEST_WIN_ARRAY_SIZE 3

MU_TEST(test_is_game_finished_vertical)
{
    GameState gamestates[TEST_WIN_ARRAY_SIZE] = {{{'x', ' ', ' '},
                                                  {'x', ' ', ' '},
                                                  {'x', ' ', ' '}},
                                                 {{' ', 'o', ' '},
                                                  {' ', 'o', ' '},
                                                  {' ', 'o', ' '}},
                                                 {{' ', ' ', 'o'},
                                                  {' ', ' ', 'o'},
                                                  {' ', ' ', 'o'}}};
    int expected[TEST_WIN_ARRAY_SIZE] = {1, 2, 2};

    int i;
    for (i = 0; i < TEST_WIN_ARRAY_SIZE; i++)
        mu_assert(is_game_finished_vertical(gamestates[i]) == expected[i], "Error, game should've been won! (vertical)");
}

MU_TEST(test_is_game_finished_horizontal)
{
    GameState gamestates[TEST_WIN_ARRAY_SIZE] = {{{'x', 'x', 'x'},
                                                  {' ', ' ', ' '},
                                                  {' ', ' ', ' '}},
                                                 {{' ', ' ', ' '},
                                                  {'o', 'o', 'o'},
                                                  {' ', 'o', ' '}},
                                                 {{'x', 'x', 'o'},
                                                  {'x', 'o', 'x'},
                                                  {'o', 'o', 'o'}}};
    int expected[TEST_WIN_ARRAY_SIZE] = {1, 2, 2};

    int i;
    for (i = 0; i < TEST_WIN_ARRAY_SIZE; i++)
        mu_assert(is_game_finished_horizontal(gamestates[i]) == expected[i], "Error, game should've been won! (horizontal)");
}