#ifndef SNAKE_GAME_CONSTS_H
#define SNAKE_GAME_CONSTS_H

#define GAME_MAP_WIDTH 32
#define GAME_MAP_HEIGHT 16

#define APPLE_DISPLAY_CHAR '*'
#define SNAKE_DISPLAY_CHAR 'o'

typedef char GameMap[GAME_MAP_WIDTH][GAME_MAP_HEIGHT];

typedef struct PointStruct {
    char x;
    char y;
} Point;

extern const Point Direction[4];

typedef struct SnakeStruct {
    Point position;
    // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
    char direction;
    struct SnakeStruct *next;
} Snake;

typedef struct GameStateStruct {
    GameMap gameMap;
    char isAlive;
    Snake snakeHead;
    Point *apple;
} GameState;

#endif //SNAKE_GAME_CONSTS_H
