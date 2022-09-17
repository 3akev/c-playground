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

enum DIRECTIONS {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

extern const Point Direction[4];

typedef struct SnakeStruct {
    Point position;
    struct SnakeStruct *next;
} Snake;

typedef struct GameStateStruct {
    GameMap gameMap;
    char isAlive;
    enum DIRECTIONS snakeDirection;
    Snake snakeHead;
    Point *apple;
} GameState;

#endif //SNAKE_GAME_CONSTS_H
