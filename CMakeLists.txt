cmake_minimum_required(VERSION 3.14)
project(Farkle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Farkle main.cpp dice.cpp dice.h player.cpp player.h game.cpp game.h)