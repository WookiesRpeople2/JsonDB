cmake_minimum_required(VERSION 3.10)
project(JsonDB C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Ilib")

set(SRC_DIR src)
set(LIB_DIR lib)
set(BUILD_DIR build)

file(GLOB SRC_FILES ${SRC_DIR}/*.c)
file(GLOB LIB_SRC_FILES ${LIB_DIR}/*.c)

set(OBJ_FILES "")
foreach (src_file ${SRC_FILES})
    get_filename_component(file_name ${src_file} NAME_WE)
    list(APPEND OBJ_FILES ${BUILD_DIR}/${file_name}.o)
endforeach ()

set(LIB_OBJ_FILES "")
foreach (lib_src_file ${LIB_SRC_FILES})
    get_filename_component(file_name ${lib_src_file} NAME_WE)
    list(APPEND LIB_OBJ_FILES ${BUILD_DIR}/${file_name}.o)
endforeach ()

add_library(JsonDBLib OBJECT ${OBJ_FILES} ${LIB_OBJ_FILES})

add_executable(JsonDB $<TARGET_OBJECTS:JsonDBLib>)

enable_testing()


add_executable(JsonDBTests test/test_main.c test/test_jsondb.c)
target_link_libraries(JsonDBTests PRIVATE JsonDBLib)


add_test(NAME JsonDBTests COMMAND JsonDBTests)


add_custom_target(lib_objects
        COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_DIR}
        COMMAND ${CMAKE_COMMAND} -E chdir ${BUILD_DIR} ${CMAKE_C_COMPILER} ${CMAKE_C_FLAGS} -c ${LIB_SRC_FILES}
        DEPENDS ${LIB_SRC_FILES})


add_dependencies(JsonDBLib lib_objects)
