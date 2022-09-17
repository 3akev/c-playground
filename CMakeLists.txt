cmake_minimum_required(VERSION 3.23)
project(snake_game C)

set(CMAKE_C_STANDARD 90)

add_executable(snake_game src/consts.c src/main.c src/game_print.c src/logic/snake.c src/logic/apple.c src/logic/collisions.c src/logic/collisions.h src/terminal_tools.c src/terminal_tools.h)
