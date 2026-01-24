cmake_minimum_required(VERSION 3.28)
project(demo_game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

set(ENGINE_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
#add_subdirectory(../app app_build)

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

add_executable(demo_game main.cpp ${GAME_SOURCES})


target_include_directories(demo_game PRIVATE ../app/include)
target_link_libraries(demo_game PRIVATE nova-engine)

target_compile_options(demo_game PRIVATE -Wall -Wextra)