#include "apple.h"
#include "../consts.h"
#include <stdlib.h>
#include <time.h>

Point *emptyPointsArray = NULL;
int arraySize = 0;

// this fills the array declared above with empty points, returning the last
// valid index
short get_empty_points(GameState *gameState) {
  short idx = 0;

  char i, j;
  for (i = 0; i < mapWidth; i++)
    for (j = 0; j < mapHeight; j++)
      if (gameState->gameMap[i][j] == ' ') {
        Point p = {i, j};
        emptyPointsArray[idx++] = p;
      }

  return --idx;
}

void place_apple(GameState *gameState) {
  if (mapWidth * mapHeight > arraySize) {
    free(emptyPointsArray);
    emptyPointsArray = malloc(mapWidth * mapHeight * sizeof(Point));
    arraySize = mapWidth * mapHeight;
  }

  short length = get_empty_points(gameState);

  srand(time(NULL));
  short idx = rand() % (length + 1);

  gameState->apple = emptyPointsArray + idx;
}

void free_apple() { free(emptyPointsArray); }
