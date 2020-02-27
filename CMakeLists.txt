cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)

add_executable(lem_in
        src/buffer.c
        src/commands.c
        src/debug.c
        src/engine.c
        src/engine_utils.c
        src/errors.c
        src/lem_in.c
        src/moving.c
        src/moving_utils.c
        src/parse.c
        src/parse_utils.c
        src/utils.c
        src/verify.c
        src/verify_utils.c
        src/copy_lines.c
        )

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)