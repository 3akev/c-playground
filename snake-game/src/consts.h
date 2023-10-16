#ifndef SNAKE_GAME_CONSTS_H
#define SNAKE_GAME_CONSTS_H

#define APPLE_DISPLAY_CHAR '*'
#define SNAKE_DISPLAY_CHAR 'o'

typedef char **GameMap;

typedef struct {
  char x;
  char y;
} Point;

enum DIRECTIONS { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

extern const Point Direction[4];
extern int mapWidth;
extern int mapHeight;

typedef struct SnakeStruct {
  Point position;
  struct SnakeStruct *prev;
  struct SnakeStruct *next;
} Snake;

typedef struct {
  GameMap gameMap;
  char isAlive;
  long score;
  enum DIRECTIONS snakeDirection;
  Snake *snakeHead;
  Snake *snakeTail;
  Point *apple;
} GameState;

#endif // SNAKE_GAME_CONSTS_H
