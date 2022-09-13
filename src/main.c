#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "consts.h"
#include "game_print.c"

void initialise_game_state(struct GameState *gameState) {
    struct Snake segment;
    srand(time(NULL));
    gameState->snakeHead.pos_x = GAME_MAP_WIDTH/2;
    gameState->snakeHead.pos_y = GAME_MAP_HEIGHT/2;
    gameState->snakeHead.direction = rand() % 4;
    gameState->snakeHead.next = &segment;
    segment.pos_x = GAME_MAP_WIDTH/2;
    segment.pos_y = GAME_MAP_HEIGHT/2;
}

void mainloop(struct GameState *gameState) {
    while(1) {
        print_game(gameState);
        int x;
        scanf("%d", &x);
    }
}

int main() {
    struct GameState gameState;
    initialise_game_state(&gameState);
    mainloop(&gameState);
}
