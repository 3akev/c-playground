#include <stdio.h>
#include "consts.h"
#include "view/game_print.h"
#include "logic/snake.h"
#include "logic/apple.h"
#include "logic/collisions.h"
#include "view/terminal_tools.h"

void initialise_game_state(GameState *gameState) {
    gameState->isAlive = 1;
    gameState->apple = NULL;

    // place snake in middle with random starting direction
    gameState->snakeHead.position.x = GAME_MAP_WIDTH/2;
    gameState->snakeHead.position.y = GAME_MAP_HEIGHT/2;
    srand(time(NULL));
    gameState->snakeDirection = rand() % 4;

    // add a segment so the game starts with 2 segments
    add_segment(&gameState->snakeHead);
}

void mainloop(GameState *gameState) {
    while(gameState->isAlive) {
        pause_for(100);
        read_input(gameState);
        check_for_collisions(gameState);
        if(gameState->isAlive)
            move_snake(gameState);
        if(gameState->apple == NULL)
            place_apple(gameState);
        print_game(gameState);
    }
    printf("GAME OVER!\n");
}

int main() {
    enableRawMode();

    GameState gameState;
    initialise_game_state(&gameState);
    initialise_printing(gameState.gameMap);

    mainloop(&gameState);
}
