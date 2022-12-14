#include "minunit.h"
#include "../src/consts.h"
#include "../src/win_check.c"

#define TEST_IS_GAME_WON_VERTICAL_ARRAY_SIZE 4

MU_TEST(test_is_game_won_vertical)
{
    GameState gamestates[TEST_IS_GAME_WON_VERTICAL_ARRAY_SIZE] = {
        {{'x', ' ', ' '},
         {'x', ' ', ' '},
         {'x', ' ', ' '}},
        {{' ', 'o', ' '},
         {' ', 'o', ' '},
         {' ', 'o', ' '}},
        {{' ', ' ', 'o'},
         {' ', ' ', 'o'},
         {' ', ' ', 'o'}},
        {{' ', ' ', 'x'},
         {' ', ' ', 'o'},
         {' ', ' ', 'o'}}};
    int expected[TEST_IS_GAME_WON_VERTICAL_ARRAY_SIZE] = {1, 2, 2, 0};

    int i;
    for (i = 0; i < TEST_IS_GAME_WON_VERTICAL_ARRAY_SIZE; i++)
        mu_assert(is_game_won_vertical(gamestates[i]) == expected[i], "Error, incorrect win check! (vertical)");
}

#define TEST_IS_GAME_WON_HORIZONTAL_ARRAY_SIZE 4

MU_TEST(test_is_game_won_horizontal)
{
    GameState gamestates[TEST_IS_GAME_WON_HORIZONTAL_ARRAY_SIZE] = {
        {{'x', 'x', 'x'},
         {' ', ' ', ' '},
         {' ', ' ', ' '}},
        {{' ', ' ', ' '},
         {'o', 'o', 'o'},
         {' ', 'o', ' '}},
        {{'x', 'x', 'o'},
         {'x', 'o', 'x'},
         {'o', 'o', 'o'}},
        {{' ', 'x', ' '},
         {'o', 'o', 'x'},
         {'x', 'x', 'o'}}};
    int expected[TEST_IS_GAME_WON_HORIZONTAL_ARRAY_SIZE] = {1, 2, 2, 0};

    int i;
    for (i = 0; i < TEST_IS_GAME_WON_HORIZONTAL_ARRAY_SIZE; i++)
        mu_assert(is_game_won_horizontal(gamestates[i]) == expected[i], "Error, incorrect win check! (horizontal)");
}

#define TEST_IS_GAME_WON_DIAGONAL_ARRAY_SIZE 3

MU_TEST(test_is_game_won_diagonal)
{
    GameState gamestates[TEST_IS_GAME_WON_DIAGONAL_ARRAY_SIZE] = {
        {{'x', ' ', 'x'},
         {' ', 'x', ' '},
         {' ', ' ', 'x'}},
        {{'o', ' ', ' '},
         {' ', 'o', 'o'},
         {' ', 'o', 'o'}},
        {{' ', 'x', ' '},
         {'o', 'o', 'x'},
         {'x', 'x', 'o'}}};
    int expected[TEST_IS_GAME_WON_DIAGONAL_ARRAY_SIZE] = {1, 2, 0};

    int i;
    for (i = 0; i < TEST_IS_GAME_WON_DIAGONAL_ARRAY_SIZE; i++)
        mu_assert(is_game_won_diagonal(gamestates[i]) == expected[i], "Error, incorrect win check! (diagonal)");
}

#define TEST_IS_GAME_WON_ANTIDIAGONAL_ARRAY_SIZE 3

MU_TEST(test_is_game_won_antidiagonal)
{
    GameState gamestates[TEST_IS_GAME_WON_ANTIDIAGONAL_ARRAY_SIZE] = {
        {{'x', ' ', 'x'},
         {' ', 'x', ' '},
         {'x', ' ', ' '}},
        {{'o', ' ', 'o'},
         {' ', 'o', 'o'},
         {'o', 'o', ' '}},
        {{' ', 'x', ' '},
         {'o', 'o', 'x'},
         {'x', 'x', 'o'}}};
    int expected[TEST_IS_GAME_WON_ANTIDIAGONAL_ARRAY_SIZE] = {1, 2, 0};

    int i;
    for (i = 0; i < TEST_IS_GAME_WON_ANTIDIAGONAL_ARRAY_SIZE; i++)
        mu_assert(is_game_won_antidiagonal(gamestates[i]) == expected[i], "Error, incorrect win check! (antidiagonal)");
}

#define TEST_IS_PLAYS_REMAINING_ARRAY_SIZE 4

MU_TEST(test_is_plays_remaining)
{
    GameState gamestates[TEST_IS_PLAYS_REMAINING_ARRAY_SIZE] = {
        {{'x', ' ', 'x'},
         {' ', 'x', ' '},
         {'x', ' ', ' '}},
        {{'o', ' ', 'o'},
         {' ', 'o', 'o'},
         {'o', 'o', ' '}},
        {{' ', 'x', ' '},
         {'o', 'o', 'x'},
         {'x', 'x', 'o'}},
        {{'x', 'x', 'o'},
         {'x', 'o', 'x'},
         {'o', 'o', 'o'}},
    };
    int expected[TEST_IS_PLAYS_REMAINING_ARRAY_SIZE] = {0, 0, 0, 3};

    int i;
    for (i = 0; i < TEST_IS_PLAYS_REMAINING_ARRAY_SIZE; i++)
        mu_assert(is_plays_remaining(gamestates[i]) == expected[i], "Error, incorrect finish check! (remaining plays)");
}

#define TEST_IS_GAME_FINISHED_ARRAY_SIZE 5

MU_TEST(test_is_game_finished)
{
    GameState gamestates[TEST_IS_GAME_FINISHED_ARRAY_SIZE] = {
        {{'x', ' ', 'x'},
         {' ', 'x', ' '},
         {'x', ' ', ' '}},
        {{'o', ' ', ' '},
         {' ', 'o', 'o'},
         {' ', 'o', 'o'}},
        {{' ', 'x', ' '},
         {'o', 'o', 'x'},
         {'x', 'x', 'o'}},
        {{'x', 'x', 'o'},
         {'x', 'o', 'x'},
         {'o', 'o', 'o'}},
        {{'x', ' ', ' '},
         {'x', ' ', ' '},
         {'x', ' ', ' '}},
    };
    int expected[TEST_IS_GAME_FINISHED_ARRAY_SIZE] = {1, 2, 0, 2, 1};

    int i;
    for (i = 0; i < TEST_IS_GAME_FINISHED_ARRAY_SIZE; i++)
        mu_assert(is_game_finished(gamestates[i]) == expected[i], "Error, incorrect finish check!");
}