#ifndef SNAKE_GAME_CONSTS_H
#define SNAKE_GAME_CONSTS_H

#define GAME_MAP_WIDTH 32
#define GAME_MAP_HEIGHT 16

typedef char GameMap[GAME_MAP_WIDTH][GAME_MAP_HEIGHT];

struct Snake {
    int pos_x;
    int pos_y;
    // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
    int direction;
    struct Snake *next;
};

struct GameState {
    GameMap gameMap;
    struct Snake snakeHead;
};

#endif //SNAKE_GAME_CONSTS_H
