cmake_minimum_required(VERSION 3.11)

# set the project name
project(ps1 C)

set(CMAKE_C_STANDARD 99)

# add the executable
add_executable(ps1 main.c math.c)