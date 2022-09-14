#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "consts.h"
#include "game_print.h"
#include "logic.h"

void initialise_game_state(GameState *gameState) {
    Snake *segment = (Snake*) malloc(sizeof(Snake));
    srand(time(NULL));
    gameState->snakeHead.position.x = GAME_MAP_WIDTH/2;
    gameState->snakeHead.position.y = GAME_MAP_HEIGHT/2;
    gameState->snakeHead.direction = rand() % 4;
    gameState->snakeHead.next = segment;
    segment->position.x = GAME_MAP_WIDTH/2;
    segment->position.y = GAME_MAP_HEIGHT/2;
}

void pause_for(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

void mainloop(GameState *gameState) {
    while(1) {
        move_snake(gameState);
        print_game(gameState);
        pause_for(500);
    }
}

int main() {
    GameState gameState;
    initialise_game_state(&gameState);
    mainloop(&gameState);
}
