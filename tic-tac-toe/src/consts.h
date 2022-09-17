#ifndef TICTACTOE_GAME_CONSTS_HEADER
#define TICTACTOE_GAME_CONSTS_HEADER

#define GAME_WIDTH_TILES 3
#define GAME_HEIGHT_TILES 3
#define NUM_PLAYERS 2

const char Players[NUM_PLAYERS] = {'x', 'o'};

typedef char GameState[GAME_WIDTH_TILES][GAME_HEIGHT_TILES];

#endif