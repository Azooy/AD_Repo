cmake_minimum_required(VERSION 3.10)
project(AD)


add_executable(AD ${CMAKE_SOURCE_DIR}/main.cpp)

target_sources(AD PRIVATE ${CMAKE_SOURCE_DIR}/src/binaries/Rucksack.cpp)
