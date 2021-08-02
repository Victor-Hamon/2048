cmake_minimum_required(VERSION 3.19)
project(2048)

set(CMAKE_CXX_STANDARD 20)

add_executable(2048 main.cpp Sources/Board.cpp Includes/Board.hpp Sources/GameObject.cpp Includes/GameObject.hpp)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(2048 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)