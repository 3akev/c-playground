#include <stdio.h>
#include "consts.h"
#include "game_print.c"

void initialise_game_map(GameMap gameMap) {
    int i, j;
    for(i=0;i<GAME_MAP_WIDTH;i++)
        for(j=0;j<GAME_MAP_HEIGHT;j++)
            gameMap[i][j] = ' ';
}

void mainloop(GameMap gameMap) {
    while(1) {
        print_game(gameMap);
        int x;
        scanf("%d", &x);
    }
}

int main() {
    GameMap gameMap;
    initialise_game_map(gameMap);
    mainloop(gameMap);
}
