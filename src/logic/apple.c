#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "apple.h"

struct EmptyPoints {
    Point *point;
    short length;
};

struct EmptyPoints get_empty_points(GameState *gameState) {
    Point *point = (Point*) malloc(GAME_MAP_WIDTH*GAME_MAP_HEIGHT*sizeof(Point));
    short idx = 0;

    char i, j;
    for(i=0; i<GAME_MAP_WIDTH; i++)
        for(j=0;j<GAME_MAP_HEIGHT; j++)
            if (gameState->gameMap[i][j] == ' ') {
                Point p = {i, j};
                point[idx++] = p;
            }

    struct EmptyPoints result = {point, --idx};
    return result;
}

Point *get_random_empty_point(GameState *gameState) {
    struct EmptyPoints emptyPoints = get_empty_points(gameState);

    srand(time(NULL));
    short idx = rand() % (emptyPoints.length+1);

    Point *p = (Point*) malloc(sizeof(Point));
    *p = emptyPoints.point[idx];
    free(emptyPoints.point);
    return p;
}

void place_apple(GameState *gameState) {
    gameState->apple = get_random_empty_point(gameState);
}