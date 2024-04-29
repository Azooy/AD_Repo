cmake_minimum_required(VERSION 3.28)
project(AD_SE_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(AD_SE_4 main.cpp
        lib/UE5/UE5.cpp
        lib/UE5/UE5.h
        lib/UE6/LinkedListQS/LinkedList.cpp
        lib/UE6/LinkedListQS/LinkedList.h
        lib/UE6/Lottery/Ringlist.cpp
        lib/UE6/Lottery/Ringlist.h)
