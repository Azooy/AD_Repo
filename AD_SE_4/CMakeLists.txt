cmake_minimum_required(VERSION 3.28)
project(AD_SE_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(AD_SE_4 main.cpp
        lib/UE6/Lottery/Ringlist.cpp
        lib/UE6/Lottery/Ringlist.h
        lib/UE6/Countsort/Countsort.cpp
        lib/UE6/Countsort/Countsort.h
        lib/UE6/Rucksack/Rucksack.cpp
        lib/UE6/Rucksack/Rucksack.h)
