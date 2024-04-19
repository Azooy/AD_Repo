cmake_minimum_required(VERSION 3.28)
project(AD_SE_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(AD_SE_4 main.cpp
        lib/UE4/UE_4.h
        lib/UE4/UE_4.cpp
        lib/UE3/UE_3.cpp
        lib/UE3/UE_3.h)
