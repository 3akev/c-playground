#include <stdio.h>
#include "minunit.h"
#include "test_win_check.c"

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_is_game_won_vertical);
    MU_RUN_TEST(test_is_game_won_horizontal);
    MU_RUN_TEST(test_is_game_won_diagonal);
    MU_RUN_TEST(test_is_game_won_antidiagonal);
    MU_RUN_TEST(test_is_game_finished);
    MU_RUN_TEST(test_is_plays_remaining);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
