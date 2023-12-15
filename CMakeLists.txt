cmake_minimum_required(VERSION 3.12)
project(JsonDB C)

# Source files
set(SOURCES
    src/testLib.c
)

target_include_directories(JsonDB PRIVATE lib)
add_executable(JsonDB ${SOURCES})

