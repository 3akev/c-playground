#include <stdio.h>
#include "minunit.h"
#include "test_win_check.c"

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_is_game_finished_vertical);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
