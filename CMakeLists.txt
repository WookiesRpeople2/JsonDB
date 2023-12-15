cmake_minimum_required(VERSION 3.12)
project(JsonDB C)

# Source files
set(SOURCES
    src/testlib.c
)


add_executable(JsonDB ${SOURCES})

