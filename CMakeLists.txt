cmake_minimum_required(VERSION 3.10)
project(TMEs)

set(CMAKE_CXX_STANDARD 11)

#add_executable(TMEs main.cpp)
#####################
##################### TME 1
#####################

add_executable( TME1
        "TME 1/List.cpp"
        "TME 1/List.h"
        "TME 1/main.cpp"
)

add_executable( TME2


        TME2/main.cpp TME2/HashMap.h)