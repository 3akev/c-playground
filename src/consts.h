#ifndef SNAKE_GAME_CONSTS_H
#define SNAKE_GAME_CONSTS_H

#define GAME_MAP_WIDTH 32
#define GAME_MAP_HEIGHT 16

typedef char GameMap[GAME_MAP_WIDTH][GAME_MAP_HEIGHT];

typedef struct PointStruct {
    int x;
    int y;
} Point;


typedef struct SnakeStruct {
    Point position;
    // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
    int direction;
    struct SnakeStruct *next;
} Snake;

typedef struct GameStateStruct {
    GameMap gameMap;
    Snake snakeHead;
} GameState;

#endif //SNAKE_GAME_CONSTS_H
