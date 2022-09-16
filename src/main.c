#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "termios.h"
#include "consts.h"
#include "game_print.h"
#include "logic/snake.h"
#include "logic/apple.h"

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
        if(gameState->apple == NULL)
            place_apple(gameState);
        read_input(&gameState->snakeHead);
        move_snake(gameState);
        print_game(gameState);
        pause_for(500);
    }
}

struct termios orig_termios;
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// This enables raw mode to allow capturing input without blocking the terminal
// derived from https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();
    GameState gameState;
    initialise_game_state(&gameState);
    initialise_printing();
    clear_map(gameState.gameMap);
    mainloop(&gameState);
}
