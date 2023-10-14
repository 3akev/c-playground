#include "snake.h"
#include <stdlib.h>
#include <unistd.h>

void add_segment(GameState *gameState) {
  Snake *segment2 = (Snake *)malloc(sizeof(Snake));
  segment2->position.x = gameState->snakeTail->position.x;
  segment2->position.y = gameState->snakeTail->position.y;
  gameState->snakeTail->next = segment2;
  segment2->prev = gameState->snakeTail;
  segment2->next = NULL;
  gameState->snakeTail = segment2;
}

void move_snake(GameState *gameState) {
  Point vector = Direction[gameState->snakeDirection];
  Point newpos = gameState->snakeHead->position;
  newpos.x += vector.x;
  newpos.y += vector.y;

  Snake *newHead = gameState->snakeTail;
  Snake *oldHead = gameState->snakeHead;

  Snake *newTail = gameState->snakeTail->prev;

  newHead->prev = NULL;
  newHead->next = oldHead;

  newHead->position = newpos;

  oldHead->prev = newHead;

  newTail->next = NULL;

  gameState->snakeHead = newHead;
  gameState->snakeTail = newTail;
}

void free_snake(GameState *gameState) {
  Snake *segment = gameState->snakeHead;
  while (segment != NULL) {
    Snake *next = segment->next;
    free(segment);
    segment = next;
  }
}
