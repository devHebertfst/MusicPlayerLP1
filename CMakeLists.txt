cmake_minimum_required(VERSION 3.2)
project(MusicPlayer VERSION 0.1 LANGUAGES CXX )
set ( CMAKE_CXX_FLAGS "-Wall" )
include_directories( include )
add_executable( program
src/main.cpp
src/func.cpp
src/playlist.cpp)