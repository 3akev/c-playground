#include "minunit.h"
#include "../src/consts.h"
#include "../src/win_check.c"

MU_TEST(test_is_game_finished_vertical)
{
#define TEST_ARRAY_SIZE 3
    GameState gamestates[TEST_ARRAY_SIZE] = {{{'x', ' ', ' '},
                                              {'x', ' ', ' '},
                                              {'x', ' ', ' '}},
                                             {{' ', 'o', ' '},
                                              {' ', 'o', ' '},
                                              {' ', 'o', ' '}},
                                             {{' ', ' ', 'o'},
                                              {' ', ' ', 'o'},
                                              {' ', ' ', 'o'}}};
    int expected[TEST_ARRAY_SIZE] = {1, 2, 2};

    int i;
    for (i = 0; i < TEST_ARRAY_SIZE; i++)
        mu_assert(is_game_finished_vertical(gamestates[i]) == expected[i], "Error, game should've been won! (vertical)");
}