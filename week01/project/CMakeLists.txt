# Please, replace ??? and %PROJECTNAME% with proper things

cmake_minimum_required(VERSION 3.10)
# ^ Minimal of version of CMake you need to begin the build

set(CMAKE_C_COMPILER gcc)
# ^ Variable of path to C compiler
set(CMAKE_CXX_COMPILER g++)
# ^ Variable of path to C++ compiler
project(Week01Project)
# ^ Name of project

message(INFO:\ ${Week01Project_SOURCE_DIR})
# ^ Log message
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Week01Project_SOURCE_DIR}/bin)
# ^ Directory where store build of project

include_directories(../include/)
# ^ Directory with headers to be included (like -I option of compiler)

add_executable(Week01Project main.cpp src/my_math.cpp src/ans_handler.cpp) 
# ^ Create executable with sources
