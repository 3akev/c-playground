cmake_minimum_required(VERSION 3.23)
project(snake_game C)

set(CMAKE_C_STANDARD 99)

add_executable(snake_game
        src/main.c
        src/view/print_game.c
        src/logic/snake.c
        src/logic/apple.c
        src/logic/collisions.c
        src/view/terminal_tools.c
        src/view/draw_game.c
        src/view/input.c)

set_target_properties(snake_game PROPERTIES COMPILE_FLAGS "-g -Wall -Wextra -pedantic")
